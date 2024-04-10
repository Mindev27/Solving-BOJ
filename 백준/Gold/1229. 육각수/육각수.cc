#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
int N;
int hexa[800];
int dp[1000005];

void input() {
  cin >> N;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  hexa[0] = 1;
  dp[0] = 0;

  // 전처리 육각수 계산
  for (int i = 1; i < 800; i++) {
    hexa[i] = hexa[i - 1] + (i + 1) * 4 - 3;
    if (hexa[i] <= 1000000)
      dp[hexa[i]] = 1;
  }

  for (int n = 1; n <= 1000000; n++) {
    if (dp[n] == -1)
      dp[n] = INF;
    for (int i = 0; i < N && hexa[i] <= n; i++) {
      dp[n] = min(dp[n], dp[n - hexa[i]] + 1);
    }
  }

  cout << dp[N] << '\n';
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