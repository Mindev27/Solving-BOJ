#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int SIZE = 105;
int n, maxHeight = 0, result = 0;
int board[SIZE][SIZE] = {};
bool visited[SIZE][SIZE] = {};

void input(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int a; cin >> a;
      board[i][j] = a;
      maxHeight = max(maxHeight, a);
    }
  }
}

void BFS(int a, int b){
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || n <= nx || ny < 0 || n <= ny)
        continue;

      if(!visited[nx][ny]){
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

// 섬의 개수를 찾는 함수
int findIsland(){
  int cnt = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        BFS(i, j);
        cnt++;
      }
    }
  }

  return cnt;
}

void solve(int water) {
  // 잠기는 곳 표시
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] <= water)
        visited[i][j] = true;
    }
  }

  result = max(result, findIsland());
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();

  for(int i = 0; i <= maxHeight; i++){
    memset(visited, false, sizeof(visited)); // 방문정보 초기화
    solve(i);
  }

  cout << result;

  return 0;
}
