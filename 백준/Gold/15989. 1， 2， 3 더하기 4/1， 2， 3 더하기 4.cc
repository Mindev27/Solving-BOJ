/*
중복있으면 점화식 뚝딱인데 어떻게 처리할까
일단 오름차순으로 생각해버리자
그러면 dp[i][j] := i번째의 합 마지막 수가 j일때
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int dp[10005][5];

// 전처리
void precalc() {
    memset(dp, 0, sizeof(dp));
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i <= 10000; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
}

void solve() {
    int N; cin >> N;
    cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
