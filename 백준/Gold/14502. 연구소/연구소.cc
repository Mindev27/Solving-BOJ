#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int row, col;
int safeArea; // 안전영역의 개수
int board[10][10] = {};
bool visited[10][10] = {};
vector<pair<int, int>> safe; // 안전영역의 위치
vector<pair<int, int>> virus; // 바이러스 위치

void input() {
  cin >> row >> col;

  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      int a; cin >> a;
      board[i][j] = a;
      if(a == 0){ // 빈칸
        safeArea++;
        safe.push_back({i, j});
      }
      else if(a == 1){ // 벽
        visited[i][j] = true;
      }
      else{ // 바이러스
        virus.push_back({i, j});
        visited[i][j] = true;
      }
      
    }
  }
}

// a, b, c를 벽으로 세울때 안전영역의 개수 반환
int BFS(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
  int result = safeArea - 3; // 초기 안전영역의 개수
  int newBoard[10][10] = {}; // 보드 복사
  bool newVisited[10][10] = {}; // 방문정보 복사
  
  // 배열 복사
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      newBoard[i][j] = board[i][j];
      newVisited[i][j] = visited[i][j];
    }
  }

  // 벽으로 바꾸기
  newBoard[a.first][a.second] = 1;
  newBoard[b.first][b.second] = 1;
  newBoard[c.first][c.second] = 1;
  newVisited[a.first][a.second] = true;
  newVisited[b.first][b.second] = true;
  newVisited[c.first][c.second] = true;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  queue<pair<int, int>> q;
  for(pair<int, int> pos : virus) // 바이러스 위치 큐에 넣기
    q.push(pos);

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || row <= nx || ny < 0 || col <= ny)
        continue;

      if(!newVisited[nx][ny] && newBoard[nx][ny] == 0){
        newVisited[nx][ny] = true;
        q.push({nx, ny});
        result--; // 안전영역의 개수 -1
      }
    }
  }

  return result;
}

void solve(){
  int result = 0;

  // 빈칸 중 3개를 벽으로 바꾸고 탐색하며 안전영역의 최대개수 찾기
  for(int i = 0; i < safe.size(); i++){
    for(int j = i + 1; j < safe.size(); j++){
      for(int k = j + 1; k < safe.size(); k++){
        result = max(result, BFS(safe[i], safe[j], safe[k]));
      }
    }
  }
  cout << result;
}

int main() {
  // freopen("input.txt" ,"r", stdin);

  input();

  solve();

  return 0;
}