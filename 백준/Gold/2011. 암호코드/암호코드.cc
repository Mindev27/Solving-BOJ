#include <iostream>
#include <cstring>

using namespace std;

int main() {
  const int MOD = 1000000;
  string code;
  cin >> code;
  code = "0" + code; // 인덱스를 맞추기 위함

  // dp 배열 초기화
  int dp[10001] = {};
  dp[0] = 1;
  dp[1] = 1;

  // dp 계산
  int curNum = code[1] - '0';
  for(int i = 2; i < code.size(); i++){
    int preNum = curNum;
    curNum = code[i] - '0';

    if(curNum != 0){
      dp[i] = dp[i - 1] % MOD;
    }
    if(10 <= preNum * 10 + curNum && preNum * 10 + curNum <= 26){
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }

  if(code[1] - '0' == 0)
    cout << 0;
  else{
    cout << dp[code.size() - 1];
  }
}