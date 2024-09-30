#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int N, M;
pii S, E;
char board[505][505];
// bool visited[505][505];
int dist[505][505];
bool isNear[505][505];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
deque<pair<pii, int>> dq;

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j];
      if (board[i][j] == 'S') { S = { i, j }; board[i][j] = '.'; }
      if (board[i][j] == 'E') { E = { i, j }; board[i][j] = '.'; }
    }
  }

  memset(dist, 0x3f, sizeof(dist));
  memset(isNear, false, sizeof(isNear));

  // 미리 모든 칸의 인접여부 계산
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];

          if (ni < 0 || N <= ni || nj < 0 || M <= nj) continue;

          if (board[ni][nj] == '#') { isNear[i][j] = true; break; }
        }
      }
    }
  }

  dist[S.X][S.Y] = 0;
  dq.push_back({ S, 0 });

  while (!dq.empty()) {
    int x = dq.front().X.X;
    int y = dq.front().X.Y;
    int d = dq.front().Y;
    dq.pop_front();

    // cout << x << ' ' << y << ' ' << d << '\n';

    if (x == E.X && y == E.Y) {
      cout << d << '\n';
      return;
    }

    if (d > dist[x][y]) continue;

    bool nearCur = isNear[x][y]; // 지금 칸이 벽에 인접한지 여부

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
      if (board[nx][ny] == '#') continue;

      int cost = 1;
      if (nearCur && isNear[nx][ny]) {
        cost = 0;
      }

      if (dist[nx][ny] > dist[x][y] + cost) {
        dist[nx][ny] = dist[x][y] + cost;
        if (cost == 0) {
          dq.push_front({ {nx, ny}, dist[nx][ny] });
        }
        else {
          dq.push_back({ {nx, ny}, dist[nx][ny] });
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
