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

int N;
int dp[101][101];    // i j 연결할때 i ~ j안에 연결하는 최대개수
int line[101][101];  // i j 연결

void input() {
  memset(dp, 0, sizeof(dp));
  memset(line, 0, sizeof(line));
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    int a, b; cin >> a >> b;
    line[a][b] = 1;
    line[b][a] = 1;
  }
}

void solve() {
  for(int i = 0; i <= 100; i++) {
    for(int j = i; j >= 1; j--) {
      for(int k = j; k < i; k++) {
        dp[j][i] = max(dp[j][i], line[i][j] + dp[j][k] + dp[k][i]);
      }
    }
  }

  cout << dp[1][100];
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
