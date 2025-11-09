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
    int N; cin >> N;
    int ans = 0;
    while(N--) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        if((a >= 1000) || (b >= 1600) || (c >= 1500) || (d != -1 && d <= 30)) {
            ans++;
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