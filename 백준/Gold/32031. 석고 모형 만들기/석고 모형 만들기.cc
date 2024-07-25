#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Cell {
  int x, y, z;
};

int R, C;
char c[205][205];
int N, M, H;
vector<Cell> adj[405][405][2];
bool visited[405][405][2];

void input() {
  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    string s; cin >> s;
    for(int j = 0; j < C; j++) {
      c[i][j] = s[j];
    }
  }
}

void makeEdge(int x1, int y1, int z1, int x2, int y2, int z2) {
  adj[x1][y1][z1].push_back({x2, y2, z2});
  adj[x2][y2][z2].push_back({x1, y1, z1});
}

void BFS(int a, int b, int c) {
  queue<Cell> q;
  q.push({a, b, c});
  visited[a][b][c] = true;

  while(!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int z = q.front().z;
    q.pop();

    // cout << x << ' ' << y << ' ' << z << '\n';

    for(int i = 0; i < adj[x][y][z].size(); i++) {
      int nx = adj[x][y][z][i].x;
      int ny = adj[x][y][z][i].y;
      int nz = adj[x][y][z][i].z;

      if(!visited[nx][ny][nz]) {
        visited[nx][ny][nz] = true;
        q.push({nx, ny, nz});
      }
    }
  }
}

void solve() {
  N = 2 * R, M = 2 * C, H = 2;
  
  // 연결 그래프로 만들기(col끼리)
  for(int i = 0; i < R - 1; i++) {
    for(int j = 0; j < C; j++) {
      makeEdge(2*i+1, 2*j, 0, 2*(i+1), 2*j, 0);
      makeEdge(2*i+1, 2*j, 1, 2*(i+1), 2*j, 1);
      makeEdge(2*i+1, 2*j+1, 0, 2*(i+1), 2*j+1, 0);
      makeEdge(2*i+1, 2*j+1, 1, 2*(i+1), 2*j+1, 1);
    }
  }
  // 연결 그래프로 만들기(row끼리)
  for(int j = 0; j < C - 1; j++) {
    for(int i = 0; i < R; i++) {
      makeEdge(2*i, 2*j+1, 0, 2*i, 2*(j+1), 0);
      makeEdge(2*i, 2*j+1, 1, 2*i, 2*(j+1), 1);
      makeEdge(2*i+1, 2*j+1, 0, 2*i+1, 2*(j+1), 0);
      makeEdge(2*i+1, 2*j+1, 1, 2*i+1, 2*(j+1), 1);
    }
  }

  // 원기둥 모양대로 연결
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(c[i][j] == 'O') { // 위아래 연결
        makeEdge(2*i, 2*j, 0, 2*i, 2*j, 1);
        makeEdge(2*i+1, 2*j, 0, 2*i+1, 2*j, 1);
        makeEdge(2*i, 2*j+1, 0, 2*i, 2*j+1, 1);
        makeEdge(2*i+1, 2*j+1, 0, 2*i+1, 2*j+1, 1);
      }
      else if(c[i][j] == 'I') {
        makeEdge(2*i, 2*j, 0, 2*i+1, 2*j, 0);
        makeEdge(2*i, 2*j+1, 0, 2*i+1, 2*j+1, 0);
        makeEdge(2*i, 2*j, 1, 2*i+1, 2*j, 1);
        makeEdge(2*i, 2*j+1, 1, 2*i+1, 2*j+1, 1);
      }
      else {
        makeEdge(2*i, 2*j, 0, 2*i, 2*j+1, 0);
        makeEdge(2*i+1, 2*j, 0, 2*i+1, 2*j+1, 0);
        makeEdge(2*i, 2*j, 1, 2*i, 2*j+1, 1);
        makeEdge(2*i+1, 2*j, 1, 2*i+1, 2*j+1, 1);
      }
    }
  }

  int ans = 0;
  memset(visited, false, sizeof(visited));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      for(int k = 0; k < H; k++) {
        if(!visited[i][j][k]) {
          BFS(i, j, k);
          ans++;
        }
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
