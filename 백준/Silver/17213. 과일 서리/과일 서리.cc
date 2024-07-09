#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
int dp[50][50];

void input() { cin >> N >> M; }

void solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < M; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < N; i++) {
    dp[i][i] = 1;
    for (int j = i + 1; j < M; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    }
  }

  cout << dp[N - 1][M - 1];
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
