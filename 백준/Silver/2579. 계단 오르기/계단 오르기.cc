#include <stdio.h>
  
int max(int a, int b){
  int result = a > b ? a : b;
  return result;
}
  
int main(void) {
  int n, stair[301] = {};
  int dp[301] = {};
  
  scanf("%d", &n);
  
  for(int i = 1; i <= n; i++){
    scanf("%d", &stair[i]);
  }
  
  //초기값 설정
  dp[1] = stair[1];
  dp[2] = stair[1] + stair[2];
  dp[3] = stair[3] + max(stair[1], stair[2]);

  if(n<4){
    printf("%d", dp[n]);

  }
  else{
    for(int i = 4; i<= n; i++){
      dp[i] = stair[i] + max(stair[i-1] + dp[i-3], dp[i-2]);
    }
    printf("%d", dp[n]);
  }
  
}