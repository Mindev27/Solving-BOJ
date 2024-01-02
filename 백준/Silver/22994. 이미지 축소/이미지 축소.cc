#include <iostream>

using namespace std;

int row, col;
int rowRatio, colRatio;
char image[1005][1005] = {};

void input() {
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < col; j++) {
      image[i][j] = input[j];
    }
  }
}

void solve() {
  // 세로 길이의 비율 계산
  rowRatio = 1005; // 충분히 큰 값으로 초기화
  for(int j = 0; j < col; j++){ // 열 하나씩 탐색
    int temp = 1;               // 임시 최대길이
    char keyChar = image[0][j]; // 비교할 시작문자
    for (int i = 1; i < row; i++) {
      if (image[i][j] != keyChar) {
        rowRatio = min(rowRatio, temp);
        temp = 1;
        keyChar = image[i][j];
      }
      else{
        temp++;
      }
    }
    // 마지막 행에서도 확인
    rowRatio = min(rowRatio, temp);
  }
  
  // 가로 길이의 비율 계산
  colRatio = 1005; // 충분히 큰 값으로 초기화
  for(int i = 0; i < row; i++){ // 행 하나씩 탐색
    int temp = 1;               // 임시 최대길이
    char keyChar = image[i][0]; // 비교할 시작문자
    for (int j = 1; j < col; j++) {
      if (image[i][j] != keyChar) {
        colRatio = min(colRatio, temp);
        temp = 1;
        keyChar = image[i][j];
      }
      else{
        temp++;
      }
    }
    // 마지막 행에서도 확인
    colRatio = min(colRatio, temp);
  }
}

void printAnswer() {
  cout << row / rowRatio << ' ';
  cout << col / colRatio << "\n";
  // 가로 세로 비율에 따라 계산하여 출력
  for (int i = 0; i < row; i += rowRatio) {
    for (int j = 0; j < col; j += colRatio) {
      cout << image[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve();

  printAnswer();

  return 0;
}