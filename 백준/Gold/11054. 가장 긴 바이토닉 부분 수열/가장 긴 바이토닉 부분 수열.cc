#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1001;
int n;
int board[MAX] = {};
int up[MAX] = {}; // 왼쪽으로 내려가는 최대개수
int down[MAX] = {}; // 오른쪽으로 내려가는 최대개수

void makeArr() {
  memset(up, 0, sizeof(up));
  memset(down, 0, sizeof(down));
  
  // up배열 만들기(왼쪽부터)
  for(int i = 2; i <= n; i++){
    for(int j = 1; j < i; j++){
      if(board[j] < board[i])
        up[i] = max(up[i], up[j] + 1);
    }
  }

  // down배열 만들기(오른쪽부터)
  for(int i = n - 1; i >= 1; i--){
    for(int j = i; j <= n; j++){
      if(board[i] > board[j])
        down[i] = max(down[i], down[j] + 1);
    }
  }
}

int findAnswer() {
  int result = 0;
  for(int i = 1; i <= n; i++){
    result = max(result, up[i] + down[i] + 1);
  }

  return result;
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> board[i];
  }

  makeArr();

  cout << findAnswer();

  return 0;
}
