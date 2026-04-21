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

string A, B;
string ans;

ull mt[26][784];
ull S[784], U[784], Tv[784], D[784];

void bitsetLcsRow(int al, int ar, int bl, int br, int rev, int *out) {
    int n = ar - al + 1;
    int m = br - bl + 1;
    int K = (n + 63) / 64;

    for(int c = 0; c < 26; c++)
        for(int k = 0; k < K; k++) mt[c][k] = 0;
    for(int i = 0; i < n; i++) {
        char ch = rev ? A[ar - i] : A[al + i];
        mt[ch - 'A'][i / 64] |= (1ULL << (i % 64));
    }
    for(int k = 0; k < K; k++) S[k] = 0;

    out[0] = 0;
    for(int j = 1; j <= m; j++) {
        char ch = rev ? B[br - (j - 1)] : B[bl + (j - 1)];
        int c = ch - 'A';
        for(int k = 0; k < K; k++) U[k] = mt[c][k] | S[k];

        ull carry = 1;
        for(int k = 0; k < K; k++) {
            Tv[k] = (S[k] << 1) | carry;
            carry = S[k] >> 63;
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

        int len = 0;
        for(int k = 0; k < K; k++) {
            S[k] = U[k] & ~D[k];
            len += __builtin_popcountll(S[k]);
        }
        out[j] = len;
    }
}

int up[50010];
int dn[50010];

void lcs(int l1, int r1, int l2, int r2) {
    if(l1 > r1 || l2 > r2) return;
    if(l1 == r1) {
        for(int j = l2; j <= r2; j++) if(B[j] == A[l1]) { ans.push_back(A[l1]); return; }
        return;
    }
    int mid = (l1 + r1) / 2;
    int m = r2 - l2 + 1;

    bitsetLcsRow(l1, mid, l2, r2, 0, up);
    bitsetLcsRow(mid + 1, r1, l2, r2, 1, dn);

    int best = -1, cut = 0;
    for(int k = 0; k <= m; k++) {
        int v = up[k] + dn[m - k];
        if(v > best) { best = v; cut = k; }
    }

    lcs(l1, mid, l2, l2 + cut - 1);
    lcs(mid + 1, r1, l2 + cut, r2);
}

void solve() {
    cin >> A >> B;
    lcs(0, (int)A.size() - 1, 0, (int)B.size() - 1);
    cout << ans.size() << '\n' << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}
