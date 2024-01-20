#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int INF = 999999;
int N, M, islandNum = 0;
int parent[10] = {};
int board[105][105] = {};
int adj[10][10] = {};

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
}

// 섬을 탐색
void BFS(int a, int b, int color) {
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  queue<pii> q;

  q.push({a, b});
  board[a][b] = color; // 방문표시대신 색칠

  while (!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] != 1)
        continue;

      if (board[nx][ny] == 1) {
        q.push({nx, ny});
        board[nx][ny] = color;
      }
    }
  }
}

// 상하좌우로 다리 뻗기
void bridge(int a, int b) {
  int cur = board[a][b] - 1; // 현재 섬의 번호

  // 상, 하, 좌, 우 네 방향에 대해 탐색
  for(int dir = 0; dir < 4; dir++) {
    int len = 0;
    int x = a, y = b;
    bool bridge_possible = false;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while(true) {
      x += dx[dir];
      y += dy[dir];

      if(x < 0 || x >= N || y < 0 || y >= M || board[x][y] == cur) {
        break;
      }

      // 다른 섬에 도달한 경우
      if(board[x][y] > 1) {
        bridge_possible = true;
        break;
      }

      len++;
    }

    // 다리를 놓을 수 있고, 길이가 2 이상인 경우
    if(bridge_possible && len >= 2) {
      int dest = board[x][y] - 1; // 도달한 다른 섬의 번호
      adj[cur][dest] = min(adj[cur][dest], len);
      adj[dest][cur] = min(adj[dest][cur], len);
    }
  }
}

// 유니온 파인드
int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

// MST 만들기
int kruscal() {
  int result = 0;
  vector<pair<int, pii>> edges; // 가중치, 시작, 끝
  
  for(int i = 1; i <= islandNum; i++) {
    for(int j = i + 1; j <= islandNum; j++) { 
      if(adj[i][j] != INF)
        edges.push_back({adj[i][j], {i, j}});
    }
  }
  
  for(int i = 1; i <= islandNum; i++)
    parent[i] = i;

  sort(edges.begin(), edges.end()); // 가중치가 작은순 정렬

  for(int i = 0; i < edges.size(); i++) {
    if(getParent(edges[i].Y.X) != getParent(edges[i].Y.Y)){
      unionParent(edges[i].Y.X, edges[i].Y.Y);
      result += edges[i].X;
    }
  }

  // 모든 섬이 연결되었는지 확인
  int p = getParent(1);
  for(int i = 2; i <= islandNum; i++) {
    if(p != getParent(i)) return -1;
  }

  return result;
}

void solve() {
  int color = 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1)
        BFS(i, j, color++);
    }
  }

  // 인접행렬 초기화
  islandNum = color - 2; // 섬의 개수
  for (int i = 1; i <= islandNum; i++)
    for (int j = 1; j <= islandNum; j++)
      adj[i][j] = INF;

  // 섬에서 다리 뻗기
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0)
        bridge(i, j);
    }
  }

  cout << kruscal(); // MST 가중치 출력
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}