#include <iostream>
#include <stack>

using namespace std;

int row, col;
int map[10000][500] = {};
bool visited[10000][500] = {};

int dfs(int a, int b);

int main() {
  cin >> row >> col;

  for(int i = 0; i < row; i++){
    string a; cin >> a;
    for(int j = 0; j < col; j++){
      if(a[j] == '.')
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }

  // //check
  // for(int i = 0; i < row; i++){

  //   for(int j = 0; j < col; j++){
  //     cout << map[i][j] << ' ';
  //   }
  //   cout << "\n";
  // }

  //가장 위쪽에 붙여서 파이프를 만들기
  int result = 0;
  for(int i = 0; i < row; i++){
    result += dfs(i, 0);
  }

  cout << result;
}

int dfs(int a, int b){
  int dx[3] = {1, 0, -1};
  int dy[3] = {1, 1, 1};
  stack<pair<int, int>> s;
  
  visited[a][b] = true;
  s.push({a, b});
  

  while(!s.empty()){
    int x = s.top().first;
    int y = s.top().second;
    s.pop();

    visited[x][y] = true;
    
    if(y == col - 1)
      return 1;

    for(int i = 0; i < 3; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
  
      if(nx < 0 || row <= nx || ny < 0 || col <= ny)
        continue;
      
      if(!visited[nx][ny] && map[nx][ny] == 0){
        s.push({nx, ny});
      }
    }
  }

  return 0;
}