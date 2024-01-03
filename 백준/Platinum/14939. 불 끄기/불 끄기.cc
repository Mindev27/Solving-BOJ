#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 10;
const int INF = 999999;
int result = INF;
int board[10] = {};

void input(int *temp) {
  for(int i = 0; i < SIZE; ++i) {
    string a; cin >> a;
    for(int j = 0; j < SIZE; ++j) {
      if(a[j] == 'O') 
        board[i] += 1 << (SIZE - j - 1);
    }
    temp[i] = board[i];
  }
}

// x, y의 버튼을 누르는 함수
void pushButton(int x, int y, int *temp) {
  int dx[5] = {0, 1, -1, 0, 0};
  int dy[5] = {0, 0, 0, 1, -1};

  for(int i = 0; i < 5; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE)
      continue;

    temp[nx] ^= (1 << (SIZE - ny - 1));
  }
}

// 첫줄이 정해졌을때 나머지 스위치를 누르는 횟수 계산
int calc(int temp[10]) {
  int cnt = 0;
  for(int i = 1; i < SIZE; ++i) {
    for(int j = 0; j < SIZE; ++j) {
      if(temp[i - 1] & (1 << (SIZE - j - 1))) { // (i-1, j)에 불이 있다면
        pushButton(i, j, temp);
        cnt++;
      }
    }
  }

  // 불이 켜져있다면 -1 반환
  for(int i = 0; i < SIZE; ++i) {
    if(temp[i] != 0) return -1;
  }
  return cnt;
}

// 첫 줄에 대해 2^10가지 경우를 모두계산
void solve(int level, int temp[10], int count) {
  if(level == SIZE) { // 끝까지 도달한 경우
    int tempCopy[10];
    memcpy(tempCopy, temp, sizeof(tempCopy));
    
    int cnt = calc(tempCopy); // 필요한 횟수 계산
    if(cnt != -1) {           // 불을 끈 경우에만 업데이트
      result = min(result, cnt + count); // count를 추가
    }
    return;
  }

  // 현재 레벨의 버튼을 누르지 않는 경우
  solve(level + 1, temp, count);

  // 현재 레벨의 버튼을 누르는 경우
  pushButton(0, level, temp);
  solve(level + 1, temp, count + 1); // 버튼을 눌렀으므로 count 증가

  // 원래 상태로 되돌림
  pushButton(0, level, temp);
}


int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int temp[10] = {};
  input(temp);
  solve(0, temp, 0);

  if(result == INF) cout << -1;
  else cout << result;
  
  return 0;
}
