#include <stdio.h>

int main(void) {
  int n, dp[1001] = {};

  //선공 승 1, 후공 승 0
  dp[1] = dp[3] = 0;
  dp[2] = dp[4] = 1;

  scanf("%d", &n);

  for(int i=5 ; i<=n ; i++){
    if(dp[i-1] == 1 && dp[i-3] == 1){
      dp[i] = 0;
    }
    else{
      dp[i] = 1;
    }
  }

  if (dp[n] == 1) {
    printf("SK");
  }

  else {
    printf("CY");
  }
}