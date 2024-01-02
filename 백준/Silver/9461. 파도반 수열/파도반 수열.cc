#include <iostream>
using namespace std;

int main() {
  long long int iTestCase, iNum, result, dp[101] = {};
  
  cin >> iTestCase;

  //초기값 설정
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;

  //Bottom-up
  for(int i = 6; i <= 100; i++){
    dp[i] = dp[i-1] + dp[i-5];
  }

  //출력
  for(int i = 0; i < iTestCase; i++){
    cin >> iNum;
    result = dp[iNum];

    cout << dp[iNum] << endl;
  }
}