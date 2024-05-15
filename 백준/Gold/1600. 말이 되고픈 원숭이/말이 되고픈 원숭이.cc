#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int K, W, H;
int board[205][205];
bool visited[205][205][35];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int ddy[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

void input() {
  cin >> K >> W >> H;
  for(int i = 0 ; i < H; i++) {
    for(int j = 0 ; j < W; j++) {
      cin >> board[i][j];
    }
  }
}


void solve() {
  memset(visited, false, sizeof(visited));
  queue<pair<pii, pii>> q;
  
  q.push({{0, 0}, {K, 0}});
  visited[0][0][K] = true;

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int k = q.front().Y.X;
    int step = q.front().Y.Y;
    q.pop();
    
    if(x == H-1 && y == W-1) {
      cout << step; return;
    }

    for(int i = 0 ; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= H || ny < 0 || ny >= W)
        continue;

      if(board[nx][ny] == 1 || visited[nx][ny][k])
        continue;

      visited[nx][ny][k] = true;
      q.push({{nx, ny}, {k, step+1}});
    }

    if(k > 0) { // k가 양수
      for(int i = 0; i < 8; i++) {
        int nx = x + ddx[i];
        int ny = y + ddy[i];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W)
          continue;

        if(board[nx][ny] == 1 || visited[nx][ny][k-1])
          continue;

        visited[nx][ny][k-1] = true;
        q.push({{nx, ny}, {k-1, step+1}});
      }
    }
  }
  cout << -1;
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
