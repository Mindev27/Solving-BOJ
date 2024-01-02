#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  if(n % 2 == 1) // 홀수라면 0
    cout << 0;
    
  else{ // 짝수라면
    long long int dp[31] = {};

    // 초기값 설정
    dp[2] = 3;
    dp[4] = 11;

    /*
      dp[i] = dp[i-2] * dp[2] +
              dp[i-4] * 2 + dp[i-6] * 2 + ...
              + dp[2] * 2 + 2; 
       다음 점화식이 성립함
    */
    for(int i = 6; i <= n; i += 2){
      dp[i] = dp[i - 2] * dp[2];  
      for(int j = i - 4; j >= 2; j -= 2){
        dp[i] += dp[j] * 2;
      }  
      dp[i] += 2;
    }

    cout << dp[n];
  }
}