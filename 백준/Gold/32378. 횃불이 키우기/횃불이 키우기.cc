#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 


const ll MAX = 1e11;
int N, k, s;
// 2^40 ~= 10^12이라 여기까지만 체크
// dp[i][j] := i번째까지 고려했을때 강화 j번 사용했을때 최대 크기
ll dp[200005][45];
ll a[200005];

void solve() {
    cin >> N >> k >> s;
    fill(&dp[0][0], &dp[0][0] + 200005 * 45, LLONG_MIN);

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    dp[0][0] = s;

    for(int i = 1; i <= N; i++){
        for(int u = 0; u <= min(k, 40); u++){
            if(dp[i-1][u] > 0){
                ll newVal = dp[i-1][u] + a[i];
                if(newVal > 0) dp[i][u] = max(dp[i][u], newVal);
            }

            if(u > 0 && dp[i-1][u-1] > 0){ 
                ll newVal = dp[i-1][u-1] * 2;
                if(newVal > 0) dp[i][u] = max(dp[i][u], newVal);
            }
        }
    }

    ll ans = LLONG_MIN;
    for(int i = 0; i <= min(k, 40); i++) {
        ans = max(ans, dp[N][i]);
    }

    if(ans <= 0) cout << -1;
    else if(ans > MAX) cout << "MEGA";
    else cout << ans;
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