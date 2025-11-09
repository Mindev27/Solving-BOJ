/*
writter : exzile_27
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double

/*

*/


void solve(){
    int p, m , c; cin >> p >> m >> c;
    int x; cin >> x;
    ll ans = LLONG_MAX;
    for(int i = 1; i <= p; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= c; k++) {
                int val = (i+j) * (j+k);
                ans = min(ans, 1LL * abs(val - x));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}