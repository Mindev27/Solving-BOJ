#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAX_N = 81;
const int MAX_X = 16001;

int n, k, x;
int a[MAX_N];
bitset<MAX_X> dp[MAX_N];

void solve() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    int ai, bi;
    cin >> ai >> bi;
    a[i] = ai;
  }
  dp[0][0] = 1;
  for (int idx = 0; idx < n; idx++) {
    int ai = a[idx];
    for (int s = min(k, idx + 1); s >= 1; s--) {
      dp[s] |= dp[s - 1] << ai;
    }
  }
  ll maxVal = 0;
  int total = k * x;
  for (int t = 0; t <= k * x; ++t) {
    if (dp[k][t]) {
      ll curVal = (ll)t * (total - t);
      if (curVal > maxVal) {
        maxVal = curVal;
      }
    }
  }
  cout << maxVal << "\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
