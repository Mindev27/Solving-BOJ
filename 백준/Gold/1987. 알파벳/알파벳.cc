#include <iostream>
#include <vector>

using namespace std;

int row, col, result = 0;
char board[25][25] = {};
bool visited[25][25] = {}; // 격자 방문 여부
bool alpha[30] = {}; // 알파벳 방문 여부
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
  cin >> row >> col;
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      cin >> board[i][j];
      visited[i][j] = false;
    }
  }
}

void solve(int x, int y, int n){
  visited[x][y] = true;
  alpha[board[x][y]- 'A'] = true;
  
  bool canMove = false;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx <= 0 || row < nx || ny <= 0 || col < ny 
               || visited[nx][ny] || alpha[board[nx][ny] - 'A'])
      continue;

    canMove = true;
    solve(nx, ny, n + 1);
  }

  if(!canMove){
    result = max(result, n);
  }

  visited[x][y] = false;
  alpha[board[x][y]- 'A'] = false;
}
int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve(1, 1, 1);

  cout << result;
}