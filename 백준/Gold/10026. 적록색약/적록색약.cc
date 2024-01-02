#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
bool visited[100][100] = {};

void BFS(int a, int b, int m[][100]);

int main() {
  int map[100][100] = {}; // 일반 보드
  int amMap[100][100] = {}; // 적록색약이 보는 보드
  
  cin >> n;

  // 입력
  for(int i = 0; i < n; i++){
    string input;
    cin >> input;

    for(int j = 0; j < n; j++){
      if(input[j] == 'R'){
        map[i][j] = 1;
        amMap[i][j] = 1;
      }
      else if(input[j] == 'G'){
        map[i][j] = 2;
        amMap[i][j] = 1;
      }
      else{
        map[i][j] = 3;
        amMap[i][j] = 2;
      }
    }
  }

  // 그냥 볼때 영역 수 계산
  int normal = 0;
  memset(visited, false, sizeof(visited));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        normal++;
        BFS(i, j, map);
      }
    }
  }
  
  // 색약일때 영역 수 계산
  int amblyopia = 0;
  memset(visited, false, sizeof(visited));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!visited[i][j]){
        amblyopia++;
        BFS(i, j, amMap);
      }
    }
  }

  cout << normal << ' ' << amblyopia;
}

// 탐색하면서 붙어있는 곳 방문표시
void BFS(int a, int b, int m[][100]){
  queue<pair<int, int>> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  int keyNum = m[a][b]; // 처음 시작하는 색깔
  
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

      if(!visited[nx][ny] && m[nx][ny] == keyNum){
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}