#include <iostream>
#include <vector>

using namespace std;

int row, col, T;
vector<int> filter; // 공기청정기의 x 좌표
int board[55][55] = {}; // 현재 시간의 상태
int nBoard[55][55] = {}; // 다음 시간의 상태
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
  cin >> row >> col >> T;
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      int a; cin >> a;
      board[i][j] = a;
      if(a == -1){        // 청정기의 좌표 저장
        filter.push_back({i});
      }
    }
  }
}

void init() {
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      nBoard[i][j] = 0;
    }
  }
}

// 미세먼지를 확산
void spreadDust(int x, int y){
  int cur = board[x][y];   // 현재위치의 미세먼지 수
  int semiDust = cur / 5;  // 주변으로 퍼져나갈때 미세먼지 수
  int canSpread = 0;       // 주변에 몇 방향으로 퍼져나가는지
  
  for(int i = 0; i < 4; i++){ // 주변으로 퍼뜨리기
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if(nx <= 0 || row < nx || ny <= 0 || col < ny || board[nx][ny] == -1)
      continue;

    canSpread++;
    nBoard[nx][ny] += semiDust;
  }

  // 현재위치 미세먼지 수
  nBoard[x][y] += cur - semiDust * canSpread; 
}

// 미세먼지 찾아서 확산시키는 함수
void findDust() {
  // 탐색하며 미세먼지 확산
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      if(board[i][j] != 0 && board[i][j] != -1)
        spreadDust(i, j);
    }
  }
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      if(board[i][j] != -1)
        board[i][j] = nBoard[i][j];
    }
  }
}

// 바람 불기
void blow() {
  // 위쪽 흡입
  for(int i = filter[0] - 2; i >= 1; i--)
    board[i + 1][1] = board[i][1];
  // 아래쪽 흡입
  for(int i = filter[1] + 2; i <= row; i++)
    board[i - 1][1] = board[i][1];

  //가장 윗줄과 아래줄 밀기
  for(int i = 2; i <= col; i++){
    board[1][i - 1] = board[1][i];
    board[row][i - 1] = board[row][i];
  }

  // 가장 오른쪽 줄 밀기
  for(int i = 2; i <= filter[0]; i++)
    board[i - 1][col] = board[i][col];

  for(int i = row - 1; i >= filter[1]; i--)
    board[i + 1][col] = board[i][col];

  // 가운데 밀기
  for(int i = col - 1; i >= 1; i--){
    board[filter[0]][i + 1] = board[filter[0]][i];
    board[filter[1]][i + 1] = board[filter[1]][i];
  }
  board[filter[0]][2] = 0;
  board[filter[1]][2] = 0;
}

int findAnswer() {
  int result = 0;
  for(int i = 1; i <= row; i++){
    for(int j = 1; j <= col; j++){
      if(board[i][j] != -1)
        result += board[i][j];
    }
  }

  return result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();
  
  while(T--){
    init();
    
    findDust();

    blow();
  }

  cout << findAnswer();
}