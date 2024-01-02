#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int dp[50001]= {};
  int n;
  
  for(int i = 0; i <= 50000; i++)
    dp[i] = i;

  cin >> n;

  for(int i = 2; i <= n; i++){
    for(int j = 2; j * j <= i; j++){
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  cout << dp[n];
}