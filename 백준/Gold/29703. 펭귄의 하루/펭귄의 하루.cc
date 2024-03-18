#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
pii start, finish;
char board[1005][1005] = {};
vector<pii> fish;

void input() {
  cin >> N >> M;
  for(int i = 0 ; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < M; j++) {
      board[i][j] = temp[j];
      if(board[i][j] == 'F')
        fish.push_back({i, j});
      if(board[i][j] == 'S')
        start = {i, j};
      if(board[i][j] == 'H')
        finish = {i, j};
    }
  }
}

void BFS(pii s, int b[][1005]) {
  queue<pii> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  q.push(s);
  b[s.X][s.Y] = 0;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(b[nx][ny] != -1 || board[nx][ny] == 'D') continue;

      b[nx][ny] = b[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

void solve() {
  int startBoard[1005][1005] = {};
  memset(startBoard, -1, sizeof(startBoard));
  
  // S에서 각 물고기로 탐색
  BFS(start, startBoard);

  int endBoard[1005][1005] = {};
  memset(endBoard, -1, sizeof(endBoard));

  // H에서 각 물고기로 탐색
  BFS(finish, endBoard);

  // 답 찾기
  int ans = 0x3f3f3f3f;
  for(pii &f : fish) {
    if(startBoard[f.X][f.Y] == -1 || endBoard[f.X][f.Y] == -1)
      continue;
    
    ans = min(ans, startBoard[f.X][f.Y] + endBoard[f.X][f.Y]);
  }

  if(ans == 0x3f3f3f3f) cout << "-1";
  else cout << ans;
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