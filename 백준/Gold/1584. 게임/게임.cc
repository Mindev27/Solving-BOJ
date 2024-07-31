#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int SIZE = 505;
int N, M;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

void input() {
  memset(visited, false, sizeof(visited));
  memset(board, 0, sizeof(board));
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int x = min(x1, x2); x <= max(x1, x2); x++) {
      for(int y = min(y1, y2); y <= max(y1, y2); y++) {
        board[x][y] = 2;
      }
    }
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int x = min(x1, x2); x <= max(x1, x2); x++) {
      for(int y = min(y1, y2); y <= max(y1, y2); y++) {
        board[x][y] = 1;
      }
    }
  }
}

void solve() {
  deque<pair<pii, int>> q;
  q.push_back({{0, 0}, 0});
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int cnt = q.front().Y;
    q.pop_front();
    
    if(x == 500 && y == 500) {
      cout << cnt;
      return;
    }

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(nx < 0 || nx > 500 || ny < 0 || ny > 500)
        continue;

      if(visited[nx][ny] || board[nx][ny] == 1)
        continue;

      visited[nx][ny] = true;
      if(board[nx][ny] == 2) {
        q.push_back({{nx, ny}, cnt + 1});
      }
      else {
        q.push_front({{nx, ny}, cnt});
      }
    }
  }
  cout << "-1";
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
