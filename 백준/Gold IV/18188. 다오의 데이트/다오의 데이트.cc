#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int H, W, N;
char board[25][25] = {};
pii start, fin;
char id[5] = {' ', 'W', 'A', 'S', 'D'};
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, -1, 0, 1};
vector<pii> canMove;

void input() {
  cin >> H >> W;
  for(int i = 1; i <= H; i++) {
    string temp; cin >> temp;
    for(int j = 1; j <= W; j++) {
      if(temp[j - 1] == 'D') {
        board[i][j] = '.';
        start = {i, j};
      }
      else if(temp[j - 1] == 'Z') {
        board[i][j] = '.';
        fin = {i, j};
      }
      else if(temp[j - 1] == '@') board[i][j] = '@';
      else board[i][j] = '.';
    }
  }

  cin >> N;
  for(int i = 0; i < N; i++) {
    char a, b; cin >> a >> b;
    pii dir = {0, 0};
    for(int j = 1; j <= 4; j++) {
      if(id[j] == a) dir.X = j;
      if(id[j] == b) dir.Y = j;
    }
    canMove.push_back(dir);
  }
}

void solve() {
  // 위치, 탐색횟수, 움직인 정보
  queue<pair<pii, pair<int, string>>> q;
  q.push({start, {0, ""}});

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int step = q.front().Y.X;
    string cmd = q.front().Y.Y;

    q.pop();

    if(x == fin.X && y == fin.Y) {
      cout << "YES\n" << cmd;
      return;
    }

    if(step >= N) continue;

    int dir = canMove[step].X;
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx >= 1 && nx <= H && ny >= 1 && ny <= W && board[nx][ny] != '@') {
      q.push({{nx, ny}, {step + 1, cmd + id[dir]}});
    }

    dir = canMove[step].Y;
    nx = x + dx[dir], ny = y + dy[dir];
    if(nx >= 1 && nx <= H && ny >= 1 && ny <= W && board[nx][ny] != '@') {
      q.push({{nx, ny}, {step + 1, cmd + id[dir]}});
    }
  }
  cout << "NO";
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
