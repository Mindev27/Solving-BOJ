#include <iostream>

using namespace std;

int main() {
  const int MOD = 9901;
  int dp[100001] = {};
  int n;
  cin >> n;

  dp[1] = 3;
  dp[2] = 7;
  
  for(int i = 3; i <= n; i++){
    dp[i] = (2 * dp[i - 1] + dp[i - 2])  % MOD;
  }

  cout << dp[n];
}