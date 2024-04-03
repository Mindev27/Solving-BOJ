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

int N;
int dp[1005], p[1005];

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> p[i];
  }
}

void solve() {
  memset(dp, 0, sizeof(dp));

  for(int i = 0; i < N; i++) {
    int maxVal = p[i];
    int minVal = p[i];

    for(int j = i; j >= 0; j--) {
      maxVal = max(maxVal, p[j]);
      minVal = min(minVal, p[j]);
      dp[i + 1] = max(dp[i + 1], dp[j] + maxVal - minVal);
    }
  }

  cout << dp[N];
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