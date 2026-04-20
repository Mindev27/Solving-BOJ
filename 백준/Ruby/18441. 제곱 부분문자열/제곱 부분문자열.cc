// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long

/*

*/

const int W = 64;

int dpLen(const vector<ull> &row, int K, int i) {
    int wIdx = i / W, bIdx = i % W;
    int s = 0;
    for(int k = 0; k < wIdx; k++) s += __builtin_popcountll(row[k]);
    if(bIdx > 0) s += __builtin_popcountll(row[wIdx] & ((1ULL << bIdx) - 1));
    return s;
}

string lcsBitset(const string &A, const string &B) {
    int n = A.size(), m = B.size();
    if(n == 0 || m == 0) return "";
    int K = (n + W - 1) / W;

    vector<vector<ull>> mt(26, vector<ull>(K, 0));
    for(int i = 0; i < n; i++)
        mt[A[i] - 'a'][i / W] |= (1ULL << (i % W));

    vector<vector<ull>> rows(m + 1, vector<ull>(K, 0));

    vector<ull> U(K), Tv(K), D(K);
    for(int j = 1; j <= m; j++) {
        int c = B[j - 1] - 'a';
        const vector<ull> &Sp = rows[j - 1];
        for(int k = 0; k < K; k++) U[k] = mt[c][k] | Sp[k];

        ull carry = 1;
        for(int k = 0; k < K; k++) {
            Tv[k] = (Sp[k] << 1) | carry;
            carry = Sp[k] >> (W - 1);
        }

        ull borrow = 0;
        for(int k = 0; k < K; k++) {
            ull a = U[k], b = Tv[k];
            ull t = a - b;
            ull nb = (a < b) ? 1ULL : 0ULL;
            ull d = t - borrow;
            if(t < borrow) nb = 1;
            D[k] = d;
            borrow = nb;
        }

        for(int k = 0; k < K; k++) rows[j][k] = U[k] & ~D[k];
    }

    int i = n, j = m;
    string res;
    while(i > 0 && j > 0) {
        int curLen = dpLen(rows[j], K, i);
        if(curLen == 0) break;
        if(A[i - 1] == B[j - 1]) {
            int diag = dpLen(rows[j - 1], K, i - 1);
            if(diag + 1 == curLen) {
                res.push_back(A[i - 1]);
                i--; j--;
                continue;
            }
        }
        int up = dpLen(rows[j - 1], K, i);
        if(up == curLen) j--;
        else i--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int lcsLen(const string &A, const string &B) {
    int n = A.size(), m = B.size();
    if(n == 0 || m == 0) return 0;
    int K = (n + W - 1) / W;

    vector<vector<ull>> mt(26, vector<ull>(K, 0));
    for(int i = 0; i < n; i++)
        mt[A[i] - 'a'][i / W] |= (1ULL << (i % W));

    vector<ull> S(K, 0), U(K), Tv(K), D(K);
    for(int j = 0; j < m; j++) {
        int c = B[j] - 'a';
        for(int k = 0; k < K; k++) U[k] = mt[c][k] | S[k];

        ull carry = 1;
        for(int k = 0; k < K; k++) {
            Tv[k] = (S[k] << 1) | carry;
            carry = S[k] >> (W - 1);
        }

        ull borrow = 0;
        for(int k = 0; k < K; k++) {
            ull a = U[k], b = Tv[k];
            ull t = a - b;
            ull nb = (a < b) ? 1ULL : 0ULL;
            ull d = t - borrow;
            if(t < borrow) nb = 1;
            D[k] = d;
            borrow = nb;
        }

        for(int k = 0; k < K; k++) S[k] = U[k] & ~D[k];
    }

    int ans = 0;
    for(int k = 0; k < K; k++) ans += __builtin_popcountll(S[k]);
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int bestLen = 0, bestP = 0;
    for(int p = 0; p <= n; p++) {
        string A = s.substr(0, p);
        string B = s.substr(p);
        int L = lcsLen(A, B);
        if(L > bestLen) { bestLen = L; bestP = p; }
    }

    if(bestLen == 0) {
        cout << "0\n";
        return;
    }

    string A = s.substr(0, bestP);
    string B = s.substr(bestP);
    string U = lcsBitset(A, B);
    cout << U.size() * 2 << '\n' << U << U << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
