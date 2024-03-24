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

const ll MOD = 1000000007;
int N, L, R;
ll dp[105][105][105];

void input() {
  cin >> N >> L >> R;
}

ll find(int n, int l, int r) {
  if(n < 1 || l < 1 || r < 1 || n < l + r - 1) return 0;

  ll &ret = dp[n][l][r];

  if (ret != -1)
    return ret;

  if (dp[n - 1][l][r] == -1)
    dp[n - 1][l][r] = find(n - 1, l, r);
  if (dp[n - 1][l - 1][r] == -1)
    dp[n - 1][l - 1][r] = find(n - 1, l - 1, r);
  if (dp[n - 1][l][r - 1] == -1)
    dp[n - 1][l][r - 1] = find(n - 1, l, r - 1);
  ret = (dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + dp[n - 1][l][r] * (n - 2)) %
      MOD;
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][1][1] = 1;
  cout << find(N, L, R);
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