#include <iostream>

using namespace std;

int n, m;
int board[55][55] = {}; // map 만들기
int result[55][55] = {}; // 정답 저장

// 입력
void input() {
  cin >> n >> m;
  for(int i = 0; i < n; i++){ // board 입력
    string temp; cin >> temp;
    for(int j = 0; j < m; j++){
      board[i][j] = temp[j] - '0';
    }
  }

  for(int i = 0; i < n; i++){  // result 입력
    string temp; cin >> temp;
    for(int j = 0; j < m; j++){
      result[i][j] = temp[j] - '0';
    }
  }
}

// 3 * 3 행렬을 뒤집는 함수
void flip(int x, int y){
  for(int i = x; i < x + 3; i++){
    for(int j = y; j < y + 3; j++){
      board[i][j] = board[i][j] ? 0 : 1; // 삼항연산자로 바꾸기
    }
  }
}

// 다르면 뒤집기
int solve() {
  int cnt = 0;
  for(int i = 0; i < n - 2; i++){
    for(int j = 0; j < m - 2; j++){
      if(board[i][j] != result[i][j]){
        flip(i, j);
        cnt++;
      }
    }
  }
  return cnt;
}

// 정답과 동일한지 확인하는 함수
bool checkSame() {
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] != result[i][j])
        return false;
    }
  }
  return true;
}

int main() {
  // (void)freopen("input.txt", "r", stdin); // 파일 읽기
  
  ios_base::sync_with_stdio(false); // fastio
  cin.tie(0); cout.tie(0);
  
  input(); // 입력
  int result = solve(); // 풀기

  if(checkSame()){   // 보드가 똑같다면
    cout << result;  // 뒤집은 횟수 출력
  }
  else{
    cout << -1;
  }

  return 0;
}