#include <iostream>

using namespace std;

int min(int x, int y){
  return x > y ? y : x; 
}

int main() {
  //0번째 R, 1번째 G, 2번째 B 일때의 최솟값
  int R, G, B, n, dp[1001][3] = {};
  
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> R >> G >> B;
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + R;
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + G;
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + B;
  }

  int minCost = min(min(dp[n][0], dp[n][1]), dp[n][2]);
  cout << minCost;
}