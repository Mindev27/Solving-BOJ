#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
char board[505][505];
int dp[505][505][4];

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++){
    string temp; cin >> temp;
    for(int j = 1; j <= n; j++){
      board[i][j] = temp[j - 1];
    }
  }
  memset(dp, -1, sizeof(dp));
}

int solve(int x, int y, int str) {
  int dx[2] = {1, 0};
  int dy[2] = {0, 1};

  if (x == n && y == n)
    return 0;

  int &result = dp[x][y][str];
  if (result != -1)
    return result;
  result = 0;

  for (int i = 0; i < 2; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > n || ny < 1 || ny > n)
      continue;

    if (board[nx][ny] == 'M') {
      result = max(result, solve(nx, ny, 1));
    } else if (board[nx][ny] == 'O' && (str == 1)) {
      result = max(result, solve(nx, ny, 2));
    } else if (board[nx][ny] == 'L' && (str == 2)) {
      result = max(result, solve(nx, ny, 3));
    } else if (board[nx][ny] == 'A' && (str == 3)) {
      result = max(result, solve(nx, ny, 0) + 1);
    } else
      result = max(result, solve(nx, ny, 0));
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);

  input();

  if (board[1][1] == 'M')
    cout << solve(1, 1, 1);
  else
    cout << solve(1, 1, 0);
}