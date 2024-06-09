#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MOD = 1000000009;
int N;
ll dp[35000];

void input() {
  cin >> N;
}

void solve() {
  dp[2] = 2;
  for(int i = 3; i <= N; i++) {
    dp[i] = (dp[i - 1] * 3) % MOD;
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
