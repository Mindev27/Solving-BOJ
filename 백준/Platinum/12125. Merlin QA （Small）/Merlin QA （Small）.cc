// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*

*/


void solve() {
    int n, m;
    cin >> n >> m;

    static int sp[105][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> sp[i][j];
    }

    int perm[8];
    for (int i = 0; i < m; i++) perm[i] = i;

    ll ans = 0;

    do {
        ll cur = 0;

        for (int i = 0; i < n; i++) {
            ll pref = 0;
            ll best = 0;

            for (int t = 0; t < m; t++) {
                pref += sp[i][perm[t]];
                if (pref > best) best = pref;
            }

            cur += best;
        }

        if (cur > ans) ans = cur;

    } while (next_permutation(perm, perm + m));

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
       cout << "Case #" << tt << ": ";
       solve();
    }
    return 0;
}