#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
int board[1005][1005];
pii times[1005][1005];    // (바이러스, 시간)
queue<pair<pii, pii>> q;  // ((위치), (바이러스, 시간))
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];

      if (board[i][j] == 1) {
        q.push({ {i, j}, {1, 0} });
        times[i][j] = { 1, 0 };
      }
      else if (board[i][j] == 2) {
        q.push({ {i, j}, {2, 0} });
        times[i][j] = { 2, 0 };
      }
    }
  }

  while (!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int type = q.front().Y.X;
    int t = q.front().Y.Y;
    q.pop();

    if (times[x][y].X == 3) continue;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || N <= nx || ny < 0 || M <= ny)
        continue;

      if (board[nx][ny] == -1 || times[nx][ny].X == 3)
        continue;

      if (times[nx][ny].X != 0) {
        if (times[nx][ny].X == type) continue;

        else if (times[nx][ny].X != type) {
          if (times[nx][ny].Y == t + 1) {
            times[nx][ny].X = 3;
          }
        }
      }

      else {
        times[nx][ny] = { type, t + 1 };
        q.push({ {nx, ny}, {type, t + 1} });
      }
    }
  }

  int one = 0, two = 0, three = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (times[i][j].X == 1) one++;
      else if (times[i][j].X == 2) two++;
      else if (times[i][j].X == 3) three++;
    }
  }

  cout << one << ' ' << two << ' ' << three << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
