#include <algorithm>
#include <cmath>
#include <complex>
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

const int INF = 1e9;
int N;
vector<int> v;
int dp[55][500005];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

int DP(int cur, int dif) {
  int &ret = dp[cur][dif];
  if (ret != 0)
    return ret;

  if (cur == N) {
    if (dif) return -INF;
    else return 0;
  }

  int n1, n2, n3;
  n1 = DP(cur + 1, dif);
  n2 = DP(cur + 1, dif + v[cur]) + v[cur];
  if(dif - v[cur] < 0) n3 = DP(cur + 1, abs(dif - v[cur])) + v[cur] - dif;
  else n3 = DP(cur + 1, abs(dif - v[cur]));
  
  return ret = max(max(n1, n2), n3);
}

void solve() {
  memset(dp, 0, sizeof(dp));
  int result = DP(0, 0);
  if(result) cout << result;
  else cout << -1;
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
