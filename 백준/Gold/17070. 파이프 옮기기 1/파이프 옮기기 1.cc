#include <iostream>
#include <vector>

using namespace std;

struct PIPE {
  int left = 0;
  int up = 0;
  int diagonal = 0;
  int count = 0;
};

int n;
int board[20][20] = {};
// 위, 왼쪽, 대각선에서 파이프의 개수, 그 지점에서 경우의 수
PIPE dp[20][20] = {};

// 입력
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 3; j <= n; j++) {
      int diagonalNum = 0;
      int leftNum = 0;
      int upNum = 0;

      if (board[i][j] == 1) { // 벽이면 패스
        continue;
      }

      // 대각선 구하기
      if (i - 1 > 0 && board[i - 1][j] != 1 && board[i][j - 1] != 1) {
        diagonalNum = dp[i - 1][j - 1].count;
      }

      // 왼쪽 구하기
      if (board[i][j - 1] != 1)
        leftNum = dp[i][j - 1].left + dp[i][j - 1].diagonal;

      // 위쪽 구하기
      if (i - 1 > 0 && board[i - 1][j] != 1)
        upNum = dp[i - 1][j].up + dp[i - 1][j].diagonal;

      // cout << "(" << i << ", " << j << ") : ";
      // cout << diagonalNum << leftNum << upNum << "\n";

      // 값을 모아서 경우의 수에 넣기
      dp[i][j].count = diagonalNum + leftNum + upNum;
      dp[i][j].diagonal = diagonalNum;
      dp[i][j].left = leftNum;
      dp[i][j].up = upNum;
    }
  }

  cout << dp[n][n].count << "\n";
}

void check() {
  cout << "left : \n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << dp[i][j].left << " ";
    }
    cout << "\n";
  }
  cout << "up : \n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << dp[i][j].up << " ";
    }
    cout << "\n";
  }
  cout << "diagonal : \n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << dp[i][j].diagonal << " ";
    }
    cout << "\n";
  }
  cout << "count : \n";
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << dp[i][j].count << " ";
    }
    cout << "\n";
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  // 초기화
  dp[1][2].left = 1;
  dp[1][2].count = 1;

  solve();

  // check();
  
  return 0;
}