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

int N, M;
int board[1005][1005];
int dp[1005][1005];

void input() {
  memset(board, 0, sizeof(board));
  memset(dp, 0, sizeof(dp));
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    string temp; cin >> temp;
    for(int j = 1; j <= M; j++) {
      board[i][j] = temp[j - 1] - '0';
    }
  }
}

void solve() {
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(board[i][j] == 0) continue;
      dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans * ans;
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