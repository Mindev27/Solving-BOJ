#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, T;
int K[105];
int S[105];
int dp[105][100005];

void input() {
  cin >> N >> T;
  for(int i = 1; i <= N; i++) {
    cin >> K[i] >> S[i];
  }
}

void solve() {
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= T; j++) {
      if(j < K[i]) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
    }
  }

  cout << dp[N][T];
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
