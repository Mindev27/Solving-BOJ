#include <iostream>

using namespace std;

int main() {
  const int DIV = 10007;
  int n, dp[1001] = {};
  cin >> n;

  dp[1] = 1;
  dp[2] = 3;
  dp[3] = 5;

  for(int i = 4; i <= n; i++){
    dp[i] = (dp[i - 1] + (2 * dp[i - 2]) % DIV) % DIV;
  }

  cout << dp[n];
}