#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;

void solve() {
  cin >> N;
  // j=0 처음 약봉지와 동일
  // j=1 약봉지가 다른 모양
  int dp[20][2];
  memset(dp, 0 ,sizeof(dp));

  dp[1][0] = 2; // 아침 점심 저녁
  dp[1][1] = 1; // 점심 저녁 아침

  for(int i = 2; i <= N; i++) {
    dp[i][1] = dp[i-1][0] + dp[i-1][1];
    dp[i][0] = 2 * (dp[i-1][0] + dp[i-1][1]);
  }

  cout << dp[N][0];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
