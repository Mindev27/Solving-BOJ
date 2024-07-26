#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
char board[55][55];
bool visited[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string s; cin >> s;
    for(int j = 0; j < M; j++) {
      board[i][j] = s[j];
    }
  }
}

int BFS(int a, int b) {
  int maxDist = 0;
  queue<pair<pii, int>> q;
  visited[a][b] = true;
  q.push({{a, b}, 0});

  while(!q.empty()) {
    int x = q.front().X.X;
    int y = q.front().X.Y;
    int dist = q.front().Y;
    q.pop();

    maxDist = max(maxDist, dist);

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;

      if(visited[nx][ny] || board[nx][ny] == 'W')
        continue;

      visited[nx][ny] = true;
      q.push({{nx, ny}, dist + 1});
    }
  }
  return maxDist;
}

void solve() {
  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(board[i][j] == 'L') {
        memset(visited, false, sizeof(visited));
        ans = max(ans, BFS(i , j));
      }
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
