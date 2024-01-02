#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

const int MAX = 1001;
int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX] = {};
deque<pair<int, int>> dq;

// 상하좌우 이동 방향
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  //입력
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for(int j = 0; j < m; j++){
      map[i][j] = row[j] - '0';
    }
  }
  // BFS로 탐색하며 벽에 칸수를 더해주기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(map[i][j] == 0 && !visited[i][j]) //빈 칸이고 방문하지 않았다면
        BFS(i,j);
    }
  }
  // 출력 (10으로 나눈 값 출력)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ans = map[i][j] % 10;
      cout << ans;
    }
    cout << "\n";
  }
}

/*
  BFS로 0인 칸을 받으면 BFS탐색을 진행
  0인 칸은 앞에 넣고 0이 아닌칸은 뒤에 넣어서 우선순위 큐처럼 사용
  0이면 값을 누적 후 0이 아닌칸은 누적값을 더해주기
*/
void BFS(int x, int y) {
  int cnt = 1;
  
  dq.push_front({x, y});
  visited[x][y] = true;
  while (!dq.empty()) {
    int a = dq.front().first;
    int b = dq.front().second;
    dq.pop_front();
    if(map[a][b] != 0){ // 벽이 나온다면 (모든 땅을 다 누적했다면)
      
      // 붙어있는 벽들에 더해주고 방문표시 지우기
      map[a][b] += cnt;
      visited[a][b] = false;
      
      while (!dq.empty()){
        a = dq.front().first;
        b = dq.front().second;
        dq.pop_front();
        visited[a][b] = false;
        map[a][b] += cnt;
      } 
      return;
    }
    
    for (int i = 0; i < 4; i++) {
      int nx = a + dx[i];
      int ny = b + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (map[nx][ny] == 0 && !visited[nx][ny]) {
          dq.push_front({nx, ny}); // 0 이므로 앞으로 push
          visited[nx][ny] = true;
          cnt++;
        }
        if (map[nx][ny] != 0 && !visited[nx][ny]) {
          dq.push_back({nx, ny}); // 벽은 뒤로 push
          visited[nx][ny] = true;
        }
      }
    }
  }
}