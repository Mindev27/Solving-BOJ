#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

const ll MOD = 1000000003;
ll N, K;
// dp[i][j] := i번째까지 고려하고, 현재 j개 가져갔을때 경우의 수
ll dp[1005][505];

void solve() {
    cin >> N;
    cin >> K;

    ll ans = 0;

    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1; // 첫번째를 색칠 안함
    dp[2][0] = 1;
    dp[2][1] = 1;

    for (int i = 3; i <= N; i++) {
        for (int j = 0; j <= (i + 1) / 2; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
            // cout << "dp[" << i << "][" << j << "] : " << dp[i][j] << '\n';
        }
    }

    // cout << dp[N][K] << '\n';
    ans += dp[N][K]; // 1번을 안색칠했으니 N번째는 색칠한거 안한거 모두 더해줌

    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1; // 첫번째를 색칠 함
    dp[2][0] = 0;
    dp[2][1] = 1;

    for (int i = 3; i <= N - 1; i++) {
        for (int j = 0; j <= (i + 1) / 2; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
            // cout << "dp[" << i << "][" << j << "] : " << dp[i][j] << '\n';
        }
    }

    ans += dp[N - 1][K]; // 1번 색칠했으니 N번은 절대 못칠하고 N-1에서 누적

    cout << ans % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}