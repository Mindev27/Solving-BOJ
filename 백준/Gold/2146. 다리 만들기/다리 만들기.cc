#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int INF = 999999;
int N, islandNum = 0;
int board[105][105] = {};

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

// 섬을 탐색
void BFS(int a, int b, int color) {
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  queue<pii> q;

  q.push({a, b});
  board[a][b] = color; // 방문표시대신 색칠

  while (!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != 1)
        continue;

      if (board[nx][ny] == 1) {
        q.push({nx, ny});
        board[nx][ny] = color;
      }
    }
  }
}

int bridge(int x, int y) {
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  bool visited[105][105];
  queue<pair<pii, int>> q;

  memset(visited, false, sizeof(visited));
  int key = board[x][y];
  q.push({{x, y}, 0});
  visited[x][y] = true;

  
  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int dist = q.front().Y;
    q.pop();

    if(board[x][y] != key && board[x][y] != 0)
      return dist;
    
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;

      if(board[nx][ny] == key || visited[nx][ny])
        continue;

      q.push({{nx, ny}, dist + 1});
      visited[nx][ny] = true;
    }
  }

  return INF; // 못찾음음
}

void solve() {
  int color = 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1)
        BFS(i, j, color++);
    }
  }

  // 섬에서 다리 뻗기
  int ans = INF;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) {
        ans = min(ans, bridge(i, j));
      }
    }
  }

  cout << ans - 1;
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