#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 105;
int N, M;
pii A, B, C;
int board[MAX][MAX];
int aDist[MAX][MAX];
int bDist[MAX][MAX];
int cDist[MAX][MAX];

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < M; j++) {
      board[i][j] = temp[j] - '0';
    }
  }
  cin >> A.X >> A.Y;
  cin >> B.X >> B.Y;
  cin >> C.X >> C.Y;
  A.X--; A.Y--;
  B.X--; B.Y--;
  C.X--; C.Y--;
}

void BFS(pii pos, int dist[MAX][MAX]) {
  bool visited[MAX][MAX] = {};
  memset(visited, false, sizeof(visited));
  queue<pair<pii, int>> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  q.push({pos, 0});
  visited[pos.X][pos.Y] = true;

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int time = q.front().Y;
    q.pop();

    dist[x][y] = time;

    for(int i = 0 ; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if(visited[nx][ny] || board[nx][ny] == 1)
        continue;

      visited[nx][ny] = true;
      q.push({{nx, ny}, time + 1});
    }
  }
}

void solve() {
  memset(aDist, INF, sizeof(aDist));
  memset(bDist, INF, sizeof(bDist));
  memset(cDist, INF, sizeof(cDist));

  BFS(A, aDist);
  BFS(B, bDist);
  BFS(C, cDist);

  int ans = INF;
  int cnt = 1;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(board[i][j] == 0) {
        int curTime = max(aDist[i][j], max(bDist[i][j], cDist[i][j]));
        if(ans > curTime) {
          ans = curTime;
          cnt = 1;
        }
        else if(ans == curTime) cnt++;
      }
    }
  }

  if(ans == INF) cout << "-1";
  else cout << ans << '\n' << cnt;
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