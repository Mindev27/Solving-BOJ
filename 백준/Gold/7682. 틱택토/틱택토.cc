#include <iostream>

using namespace std;

void solve(string s) {
  char board[5][5] = {};
  int xNum = 0;
  int oNum = 0;

  for (int i = 0; i < 9; i++) {
    if (s[i] == 'X') {
      xNum++;
      board[i / 3][i % 3] = 'X';
    } else if (s[i] == 'O') {
      oNum++;
      board[i / 3][i % 3] = 'O';
    } else {
      board[i / 3][i % 3] = '.';
    }
  }

  if (xNum != oNum && xNum != oNum + 1) {
    cout << "invalid\n";
    return;
  }

  int xLine = 0;
  int oLine = 0;

  //가로 확인
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == '.')
        continue;
      else if (board[i][0] == 'X')
        xLine++;
      else
        oLine++;
    }
  }
  //세로 확인
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      if (board[0][j] == '.')
        continue;
      else if (board[0][j] == 'X')
        xLine++;
      else
        oLine++;
    }
  }
  // 대각선 확인
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] != '.') {
      if (board[0][0] == 'X')
        xLine++;
      else
        oLine++;
    }
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] != '.') {
      if (board[0][2] == 'X')
        xLine++;
      else
        oLine++;
    }
  }

  if (oLine > 0 && xLine > 0)
    cout << "invalid\n";
  else if (oLine > 0) {
    if (xNum == oNum)
      cout << "valid\n";
    else
      cout << "invalid\n";
  } else if (xLine > 0) {
    if (xNum == oNum + 1)
      cout << "valid\n";
    else
      cout << "invalid\n";
  } else if (xNum + oNum == 9)
    cout << "valid\n";
  else
    cout << "invalid\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    string input;
    cin >> input;
    if (input == "end")
      break;
    solve(input);
  }

  return 0;
}