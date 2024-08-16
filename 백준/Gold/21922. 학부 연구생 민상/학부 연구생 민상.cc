#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
vector<pii> start;
int board[2005][2005];
bool visited[2005][2005];

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> board[i][j];
      if(board[i][j] == 9) {
        start.push_back({i, j});
      }
    }
  }
}

void solve() {
  // 0: 아래, 1: 위, 2: 오른쪽, 3: 왼쪽
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  // cnvt[i][j] : i번 물건을 만날때 j방향으로 변화
  int cnvt[5][4] = { 
    {0,1,2,3},
    {0,1,-1,-1},
    {-1,-1,2,3},
    {3,2,1,0},
    {2,3,0,1},
  };
  queue<pair<pii, int>> q;   // {pos, dir}

  for(auto s : start) {
    for(int i = 0; i < 4; i++) {
      q.push({s, i});
    }
  }

  memset(visited, false, sizeof(visited));

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int dir = q.front().Y;
    q.pop();
    
    visited[x][y] = true;
    if(dir == -1) continue;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
      continue;

    if(board[nx][ny] == 9)
      continue;

    int nDir = cnvt[board[nx][ny]][dir];
    

    q.push({{nx, ny}, nDir});
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(visited[i][j]) ans++;
    }
  }

  cout << ans;
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
