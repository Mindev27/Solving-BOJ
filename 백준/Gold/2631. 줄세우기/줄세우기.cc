#include <iostream>

using namespace std;

int n;
int board[205] = {};
int dp[205] = {};

void input() {
  cin >> n;
  
  for(int i = 1; i <= n; i++){
    cin >> board[i];
  }
}

void solve() {
  dp[1] = 1;

  for(int i = 2; i <= n; i++){
    dp[i] = 1; // 각 원소 자체로 길이 1의 증가하는 부분 수열이 될 수 있음
    for(int j = 1; j < i; j++){
      if(board[j] < board[i])
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
}

void printAnswer() {
  int result = 0;
  
  for(int i = 1; i <= n; i++){
    result = max(result, dp[i]);
  }

  cout << n - result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve();

  printAnswer();

  return 0;
}