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

const int MAXN = 50005;
const int W = 64;

int K;
ull mt[26][MAXN / W + 5];
ull S[MAXN / W + 5];
ull U[MAXN / W + 5];
ull T[MAXN / W + 5];
ull D[MAXN / W + 5];

void solve() {
    string A, B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    K = (n + W - 1) / W;
    if(K == 0) { cout << 0 << '\n'; return; }

    for(int c = 0; c < 26; c++)
        for(int k = 0; k < K; k++) mt[c][k] = 0;
    for(int i = 0; i < n; i++)
        mt[A[i] - 'A'][i / W] |= (1ULL << (i % W));
    for(int k = 0; k < K; k++) S[k] = 0;

    for(int j = 0; j < m; j++) {
        int c = B[j] - 'A';
        for(int k = 0; k < K; k++) U[k] = mt[c][k] | S[k];

        ull carry = 1;
        for(int k = 0; k < K; k++) {
            T[k] = (S[k] << 1) | carry;
            carry = S[k] >> (W - 1);
        }

        ull borrow = 0;
        for(int k = 0; k < K; k++) {
            ull a = U[k], b = T[k];
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
    cout << ans << '\n';
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
