#include <iostream>

using namespace std;

int main() {
  const int MOD = 1000000000;
  const int SIZE = 205;
  long long int dp[SIZE][SIZE] = {};
  int n, k;
  cin >> n >> k;

  // 초기화
  for(int j = 0; j <= n; j++){
    dp[1][j] = 1;
  }
  
  // dp[i][j] = dp[i - 1][0] + ... + dp[i - 1][j] 가 성립
  for(int i = 2; i <= k; i++){
    for(int j = 0; j <= n; j++){
      for(int k = 0; k <= j; k++){
        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
      }
    }
  }
  
  cout << dp[k][n];
}
