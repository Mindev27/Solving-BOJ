#include <stdio.h>
#define SIZE 1000001

int min(int a, int b){
  return a > b ? b : a;
}

int main(){
  int n, dp[SIZE] = {0,};
  
  scanf("%d" ,&n);

  dp[1] = 0;
  dp[2] = dp[3] = 1;
  
  for(int i = 4; i <= n; i++){
    dp[i] = dp[i-1] + 1;

    //2로 나누어진다면
    if(i % 2 == 0){
      dp[i] = dp[i] > dp[i/2]+1 ? dp[i/2]+1 : dp[i];
    }

    //3으로 나누어진다면
    if(i % 3 == 0){
      dp[i] = dp[i] > dp[i/3]+1 ? dp[i/3]+1 : dp[i];
    }
  }

  printf("%d", dp[n]);
}
