#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <set>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int W, H;
pii start;
int board[55][55];
bool visited[55][55];

void input() {
  cin >> W >> H;
  for (int i = 0; i < H; i++) {
    string x; cin >> x;
    for(int j = 0; j < W; j++) {
      board[i][j] = x[j];
      
      if(board[i][j] == 'P') {
        start = {i, j};
        board[i][j] = '.';
      }
    }
  }
}


void solve() {
  queue<pii> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  
  q.push(start);
  visited[start.X][start.Y] = true;
  int goldCnt = 0;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    if(board[x][y] == 'G') goldCnt++;
    bool canTravel = true; // 여기서 더 탐색해도 되는가

    // 주변이 위험한지 확인
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= H ||  ny < 0 || ny >= W) continue;

      if(board[nx][ny] == 'T') {
        canTravel = false;
        break;
      }
    }

    // 위험하면 탐색 종료
    if(!canTravel) continue;

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= H ||  ny < 0 || ny >= W) continue;

      if(board[nx][ny] == '#' || visited[nx][ny]) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }

  cout << goldCnt;
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
