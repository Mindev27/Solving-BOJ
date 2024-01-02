#include <iostream>

using namespace std;

int n;
int paper[2200][2200]; // 3^7 = 2187
int num[3] = {}; // 인덱스가 값의 개수

void input(){
  cin >> n;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int a; cin >> a;
      paper[i][j] = a + 1; // 계산하기 편하도록 1더하기
    }
  }
}

// solve(한변의 길이, 시작 좌표)
void solve(int size, int x, int y){
  if(size == 1){ // 크키가 1이면 그 값 더해주기
    num[paper[x][y]]++;
    return;
  }
  
  bool allSame = true; // 모두 같은 수 인지 여부
  int keyNum = paper[x][y]; // 같은지 확인할 숫자
  
  for(int i = x; i < size + x; i++){
    for(int j = y; j < size + y; j++){
      if(keyNum != paper[i][j]) // 하나라도 다르다면
        allSame = false; // 모두 같지 않다로 변경
    }
  }

  // 모두 같다면
  if(allSame){
    num[keyNum] += 1; // 개수만큼 더해주기
    return;
  }

  int nextSize = size / 3; // 다음 한변 길이

  // 9조각의 사각형에 재귀적으로 호출
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      solve(nextSize, x + nextSize * i, y + nextSize * j);
    }
  }
}

int main() {
  input();
  
  solve(n, 0, 0);

  for(int i = 0; i < 3; i++){
    cout << num[i] << "\n";
  }
}