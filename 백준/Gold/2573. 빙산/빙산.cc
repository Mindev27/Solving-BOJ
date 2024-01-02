#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int map[300][300] = {};
int nextMap[300][300] = {};
bool visited[300][300] = {};
int row, col;

void input();
int solve();
void BFS(int a, int b);

int main() {
  input();

  int result = solve();
  cout << result;
}

void input() {
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> map[i][j];
    }
  }
}

int solve() {
  int countYear = 0; // 몇년이 지났는지

  while (true) {
    
    
    memset(visited, false, sizeof(visited)); // 초기화
    memset(nextMap, false, sizeof(nextMap)); // 초기화

    int IceNum = 0; // 빙산의 개수
    
    // 순회하면서 BFS탐색
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (map[i][j] != 0 && !visited[i][j]) {    
          BFS(i, j); // 못찾았다면 탐색
          IceNum++;
        }
      }
    }

    if (IceNum == 0)
      return 0; // 못찾고 다 녹으면 0 리턴
    else if (IceNum >= 2)
      return countYear; // 2개 이상으로 쪼개진다면 답 출력

    // nextMap의 내용을 map에 복사
    for (int x = 0; x < row; x++) {
      for (int y = 0; y < col; y++) {
        map[x][y] = nextMap[x][y];
      }
    }
    
    countYear++;
  }
}

// map을 탐색하고 newMap에 저장
void BFS(int a, int b) {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int>> q;

  q.push({a, b});
  visited[a][b] = true;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int height = map[x][y];
    q.pop();

    // 인접한 칸 탐색
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || row <= nx || ny < 0 || col <= ny)
        continue;

      if(map[nx][ny] == 0)
        height--;

      if(map[nx][ny] != 0 && !visited[nx][ny]){
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
    
    // 녹은 정보를 nextMap에 옳기기
    if(height <= 0) nextMap[x][y] = 0;
    else nextMap[x][y] = height;
  }
}