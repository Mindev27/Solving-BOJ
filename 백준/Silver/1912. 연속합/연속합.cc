#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N;
int a[100005];
int dp[100005];

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 0;
  int answer = -99999999;

  for(int i = 1; i <= N; i++) {
    dp[i] = max(dp[i - 1] + a[i], a[i]);
    answer = max(dp[i], answer);
  }

  cout << answer;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}