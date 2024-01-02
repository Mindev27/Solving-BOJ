#include <iostream>

using namespace std;

int m, n;
int map[501][501] = {};
int dp[501][501] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y);

int main() {
  cin >> m >> n;

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> map[i][j];
      dp[i][j] = -1;
    }
  }

  // top-down으로 dp돌리기
  int result = dfs(1, 1);
  cout << result;
}

// 끝까지 탐색해서 도착지에 도달하는 경우의 수를 세기
int dfs(int x, int y){
  if(x == m && y == n) 
    return 1;
  if(dp[x][y] != -1) 
    return dp[x][y];

  dp[x][y] = 0;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(0 < nx && nx <= m && 0 < ny && ny <= n){
      if(map[nx][ny] < map[x][y]){ // 원래 값보다 더 작다면
        dp[x][y] = dp[x][y] + dfs(nx, ny);
      }
    }
  }

  return dp[x][y];
}