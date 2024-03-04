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

int H, W, O, F;
pii start, finish;
int board[105][105];
bool visited[105][105];

void input() {
  memset(board, 0, sizeof(board));
  memset(visited, 0, sizeof(visited));

  cin >> H >> W >> O >> F;
  cin >> start.X >> start.Y >> finish.X >> finish.Y;

  for (int i = 0; i < O; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    board[a][b] = c;
  }
}

bool BFS() {
  queue<pair<pii, int>> q; // 좌표, 남은 힘
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  
  q.push({start, F});
  visited[start.X][start.Y] = F;

  while(!q.empty()) {
    pii cur = q.front().X;
    int curF = q.front().Y;
    q.pop();

    if(cur == finish) return true;
    if(curF <= 0) continue;

    for(int i = 0 ; i < 4 ; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];

      if(nx < 1 || nx > H || ny < 1 || ny > W) continue;
      
      if(!visited[nx][ny]) {
        int heightGap = board[nx][ny] - board[cur.X][cur.Y];
        if(heightGap <= curF) {
          visited[nx][ny] = true;
          q.push({{nx, ny}, curF - 1});
        }
      }
    }
  }
  
  return false;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    input();
    if(BFS()) cout << "잘했어!!\n";
    else cout << "인성 문제있어??\n";
  }

  return 0;
}
