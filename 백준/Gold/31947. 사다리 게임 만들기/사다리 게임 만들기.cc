#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M, S, E;
ld dp[10005][505];

void input() {
  cin >> N >> M >> S >> E;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][S] = 1;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      if(j == 1) {
        dp[i][j] += dp[i-1][j] * (N - 2);
        dp[i][j] += dp[i-1][j + 1];
      }
      else if(j == N) {
        dp[i][j] += dp[i-1][j] * (N - 2);
        dp[i][j] += dp[i-1][j - 1];
      }
      else {
        dp[i][j] += dp[i-1][j] * (N - 3);
        dp[i][j] += dp[i-1][j + 1];
        dp[i][j] += dp[i-1][j - 1];
      }
      dp[i][j] /= (N - 1);
    }
  }
  
  cout.precision(15);
  cout << dp[M][E];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
