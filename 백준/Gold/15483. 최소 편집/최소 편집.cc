#include <iostream>
#include <string>

using namespace std;

const int MAX_LEN = 1005;
int D[MAX_LEN][MAX_LEN];

// EditDist 함수 선언
int EditDist(int n, string X, int m, string Y, int ins, int del, int chg) {

  D[0][0] = 0;
  
  // 초기화
  for (int i = 1; i <= n; ++i)
    D[i][0] = D[i - 1][0] + del;
  for (int j = 1; j <= m; ++j)
    D[0][j] = D[0][j - 1] + ins;

  // 편집 거리 계산
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int c = (X[i - 1] == Y[j - 1]) ? 0 : chg;
      D[i][j] = min(D[i - 1][j] + del, min(D[i][j - 1] + ins, D[i - 1][j - 1] + c));
    }
  }

  return D[n][m];
}

int main() {
  string X, Y;

  cin >> X;

  cin >> Y;

  int n = X.size();
  int m = Y.size();
  int ins = 1, del = 1, chg = 1; // 삽입, 삭제, 변경 비용

  // init
  for(int i = 0; i < MAX_LEN; i++) {
    for(int j = 0; j < MAX_LEN; j++) {
      D[i][j] = 0;
    }
  }

  
  
  int cost = EditDist(n, X, m, Y, ins, del, chg);
  
  // // 테이블 출력
  // cout << "편집거리 테이블" << '\n';
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= m; ++j) {
  //     cout << D[i][j] << "  ";
  //   }
  //   cout << '\n';
  // }
  
  cout << cost << '\n';

  return 0;
}