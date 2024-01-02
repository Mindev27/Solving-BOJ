#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];  // 최단 거리 표시

// 상하좌우 이동 방향
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS();

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  int answer = BFS();
  cout << answer;
}

int BFS() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 1;  // 시작 위치

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    // 목적지에 도착한 경우 최단 거리 반환
    if (x == n - 1 && y == m - 1)
      return dist[x][y];

    // 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위를 벗어나는 경우 무시
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;

      if (map[nx][ny] == 1 && dist[nx][ny] == 0) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}
