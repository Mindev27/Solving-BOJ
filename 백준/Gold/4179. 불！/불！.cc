#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int SIZE = 1000;
int row, col;
int playerX, playerY; // 시작 위치
bool visited[SIZE][SIZE] = {}; // 방문정보 저장장
int board[SIZE][SIZE] = {}; // 맵의 정보저장
queue<pair<int, pair<int, int>>> fires; // 시간, x좌표, y좌표
queue<pair<int, pair<int ,int>>> q; // 플레이어 정보
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void input() {
  cin >> row >> col;

  for(int i = 0; i < row; i++) {
    
    string temp; cin >> temp;
    
    for(int j = 0; j < col; j++) {
      if(temp[j] == '.') // 빈공간
        board[i][j] = INT_MAX;
      

      else if(temp[j] == '#') // 벽
        board[i][j] = -1;

      
      else if(temp[j] == 'J') { // 시작위치 저장
        playerX = i;
        playerY = j;
        board[i][j] = INT_MAX;
      }
        
      else { // 불의 위치 저장
        fires.push({0, {i, j}});
        board[i][j] = 0; // 0초에 불이 번진다는 뜻
      }

      visited[i][j] = false; // 방문 정보 초기화
    }
  }

  while(!q.empty()) q.pop(); // 큐 초기
}

// 불을 번지게 하는 함수 (BFS)
void spreadFire() {
  while(!fires.empty()) {
    int curTime = fires.front().first;
    int x = fires.front().second.first;
    int y = fires.front().second.second;
    fires.pop();

    // 4방향 탐색
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위를 벗어나거나 벽이라면 탐색 X
      if(nx < 0 || row <= nx || ny < 0 || col <= ny || board[nx][ny] == -1)
        continue;

      // 현재 시간보다 더 빠르다면 초기화
      if(board[nx][ny] > curTime + 1){
        fires.push({curTime + 1, {nx, ny}});
        board[nx][ny] = board[x][y] + 1; // 업데이트
      }

    }
  }
}

int movePlayer(){
  
  q.push({0, {playerX, playerY}});
  visited[playerX][playerY] = true;
  
  while(!q.empty()) {
    int curTime = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    // 4방향 탐색
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 탈출한다면 답 반환
      if(nx < 0 || row <= nx || ny < 0 || col <= ny)
        return curTime + 1;
      
      // 벽이거나 방문하면 탐색 X
      if(board[nx][ny] == -1 || visited[nx][ny])
        continue;

      // 불보다 먼저 도착한다면 계속 탐색
      if(curTime + 1 < board[nx][ny]){
        visited[nx][ny] = true;
        q.push({curTime + 1, {nx, ny}});
      }
    }
  }

  return -1; // 불가능하다면 -1 반환
}

void check() {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cout << board[i][j] << ' ';
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  input();

  spreadFire();

  // check();

  int result = movePlayer();
  
  if(result == -1) cout << "IMPOSSIBLE\n";
  else cout << result << "\n";
  
}