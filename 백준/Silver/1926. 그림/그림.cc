#include <iostream>
#include <queue>

using namespace std;

int row, col;
int board[505][505] = {};
bool visited[505][505] = {};
void input() {
  cin >> row >> col;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> board[i][j];
    }
  }
}

int BFS(int a, int b) {
  int result = 1;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= row || ny < 0 || ny >= col)
        continue;

      if(visited[nx][ny] || board[nx][ny] == 0)
        continue;

      visited[nx][ny] = true;
      result++;
      q.push({nx, ny});
    }
  }

  return result;
}

void solve() {
  int cnt = 0;
  int maxSize = 0;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(board[i][j] == 1 && !visited[i][j]){
        maxSize = max(maxSize, BFS(i, j));
        cnt++;
      }
    }
  }

  cout << cnt << '\n' << maxSize;
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