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

const int INF = 0x3f3f3f3f;
int A, B, C;
int dp[3005][3005];
string X, Y;

void input() {
  cin >> A >> B >> C;
  cin >> X >> Y;
}

int DP(int a, int b) {
  if(a == X.length()) return (Y.length() - b)*B;
  if(b == Y.length()) return (X.length() - a)*B;
  int& ret = dp[a][b];

  if(ret != -INF) return ret;
  ret = max(DP(a + 1, b) + B, DP(a, b + 1) + B);
  if(X[a] == Y[b])
    ret = max(ret, A + DP(a + 1, b + 1));
  else 
    ret = max(ret, C + DP(a + 1, b + 1));

  return ret;
}

void solve() {
  for(int i = 0; i < 3000; i++) {
    for(int j = 0; j < 3000; j++) {
      dp[i][j] = -INF;
    }
  }

  cout << DP(0, 0);
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}