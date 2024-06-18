#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MOD 786433
#define G 1000

using namespace std;

int N, wCnt;
pii start = {0, 0};
char board[105][105];
bool visited[105][105];

void input() {
  wCnt = 0;
  memset(visited, false, sizeof(visited));

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      board[i][j] = s[j];
      if (board[i][j] == 'w') {
        start = {i, j};
        board[i][j] = '-';
        wCnt++;
      }
    }
  }
}

void solve() {
  int cnt = 1;
  int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
  int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
  queue<pii> q;
  visited[start.X][start.Y] = true;
  q.push(start);

  while (!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if (board[nx][ny] == 'b' || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      cnt++;
    }
  }

  cout << cnt - wCnt << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    input();
    solve();
  }

  return 0;
}
