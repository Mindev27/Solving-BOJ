#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
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

const ll MOD = 1000000000;
int N;
ll dp[10][100];

void input() {
  cin >> N;
}

ll backTracking(int cur, int step) {
  if(step == N) {
    return 1;
  }

  ll &ret = dp[cur][step];
  if(ret != -1) return ret;

  ret = 0;
  if(cur != 0) ret += backTracking(cur - 1, step + 1);
  if(cur != 9) ret += backTracking(cur + 1, step + 1);

  return ret % MOD;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  ll res = 0;
  for(int i = 1; i <= 9; i++) {
    res += backTracking(i, 1);
    res %= MOD;
  }

  cout << res;
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
