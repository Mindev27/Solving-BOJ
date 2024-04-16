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

int N, M, K;
ll dp[105][105];
vector<pair<pii, pii>> broken;

void input() {
  cin >> N >> M >> K;
  for(int i = 0; i < K; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    broken.push_back({{a, b}, {c, d}});
    broken.push_back({{c, d}, {a, b}});
  }
}

bool isBroken(int sx, int sy, int ex, int ey) {
  for(auto i : broken) {
    if(sx == i.X.X && sy == i.X.Y && ex == i.Y.X && ey == i.Y.Y)
      return true;
  }
  return false;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= M; j++) {
      if(i - 1 >= 0) {
        if(!isBroken(i, j, i - 1, j))
          dp[i][j] += dp[i - 1][j];
      }
      if(j - 1 >= 0) {
        if(!isBroken(i, j, i, j - 1))
          dp[i][j] += dp[i][j - 1];
      }
    }
  }

  cout << dp[N][M] << '\n';
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