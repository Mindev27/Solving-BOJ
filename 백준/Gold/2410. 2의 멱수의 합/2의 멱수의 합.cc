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

const int MOD = 1000000000;
int N;
int dp[1000005]; // i번째 수의 경우의 수

void input() {
  cin >> N;
}

void solve() {
  memset(dp, 0, sizeof(dp));

  dp[1] = 1;

  for(int i = 2; i <= N; i++) {
    if(i % 2 == 0) {
      dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
    }
    else {
      dp[i] = dp[i - 1];
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