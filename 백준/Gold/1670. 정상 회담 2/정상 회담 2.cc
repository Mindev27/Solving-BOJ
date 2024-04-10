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

const ll MOD = 987654321;
int N;
ll dp[10005];

void input() {
  cin >> N;
}

ll DP(int n) {
  ll &ret = dp[n];
  if(ret != -1) return ret;

  ret = 0;
  for(int i = 0; i <= n - 2; i++) {
    ret += (DP(i) * DP(n - 2 - i));
    ret %= MOD;
  }

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0] = dp[2] = 1;
  dp[1] = dp[3] = 0;

  cout << DP(N);
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