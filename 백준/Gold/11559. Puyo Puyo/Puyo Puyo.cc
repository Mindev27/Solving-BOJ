#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int N = 12, M = 6;
char board[15][10];
bool visited[15][10];

void input() {
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j];
    }
  }
}

void check() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}

void gravity() {
  for (int j = 0; j < M; j++) {
    int top = N - 1;
    for (int i = N - 1; i >= 0; i--) {
      if (board[i][j] != '.') {
        char c = board[i][j];
        board[i][j] = '.';
        board[top--][j] = c;
      }
    }
  }
}

bool BFS(int a, int b) {
  queue<pii> q;
  vector<pii> blocks;
  
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  visited[a][b] = true;
  char key = board[a][b];
  q.push({a, b});

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();
    blocks.push_back({x, y});

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;

      if(board[nx][ny] == key && !visited[nx][ny]) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
  
  if(blocks.size() >= 4) {
    for(auto block : blocks) {
      board[block.X][block.Y] = '.';
    }
    return true;
  }
  return false;
}

void solve() {
  int result = 0;

  // gravity();
  // check();
  
  while(true) {
    memset(visited, false, sizeof(visited));
    bool isBoom = false;
    gravity();

    for(int i = 0; i < N; i++) {
      for(int j = 0 ; j < M; j++) {
        if(board[i][j] !=  '.') {
          isBoom |= BFS(i, j);
        }
      }
    }

    if(!isBoom) break;
    result++;
  }

  cout << result;
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
