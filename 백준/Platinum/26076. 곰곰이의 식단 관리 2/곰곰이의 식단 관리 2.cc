#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
int board[2020][2020];

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> board[i][j];
    }
  }
}

bool BFS(int a, int b) {
  bool visited[2020][2020];
  memset(visited, false, sizeof(visited));
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  queue<pii> q;

  q.push({a, b});
  visited[a][b] = true;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    if(x == N && y == M) return true;
    
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if(board[nx][ny] == 1 || visited[nx][ny]) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return false;
}

void paint(int a, int b, int color) {
  int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
  bool visited[2020][2020];
  memset(visited, false, sizeof(visited));
  queue<pii> q;

  q.push({a, b});
  visited[a][b] = true;
  board[a][b] = color;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for(int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1)
        continue;

      if(board[nx][ny] == 0 || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      board[nx][ny] = color;
    }
  }
}
void solve() {
  // BFS로 도달경로가 있는지 확인 없다면 답은 0
  if(BFS(1, 1) == false) {
    cout << 0; return;
  }

  board[N+1][0] = 1;
  for(int i = 2, j = 0; i <= N; i++) {
    board[i][j] = 1;
  }
  for(int i = N + 1, j = 1; j <= M - 1; j++) {
    board[i][j] = 1;
  }

  board[0][M + 1] = 1;
  for(int i = 1, j = M + 1; i <= N - 1; i++) {
    board[i][j] = 1;
  }
  for(int i = 0, j = 2; j <= M; j++) {
    board[i][j] = 1;
  }
  
  // (N + 1, 0)에서 색칠
  paint(N + 1, 0, 2);

  // (0, M + 1)에서 색칠
  paint(0, M + 1, 3);

  // cout << "++++++++++\n";

  // for(int i = 0; i <= N + 1; i++) {
  //   for(int j = 0; j <= M + 1; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }


  int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(board[i][j] != 0) continue;
      if(i == 1 && j == 1) continue;
      if(i == N && j == M) continue;

      bool isTwo = false, isThree = false;
      for(int k = 0; k < 8; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        
        if(board[nx][ny] == 2) isTwo = true;
        if(board[nx][ny] == 3) isThree = true;
      }

      if(isTwo && isThree) {
        cout << 1; return;
      }
    }
  }

  cout << 2;
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
