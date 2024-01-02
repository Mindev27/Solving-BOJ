#include <stdio.h>

int main(void) {
  
  int dp[1001] = {0};

  int n;

  scanf("%d", &n);

  dp[1] = 1;
  dp[2] = 0;
  dp[3] = 1;
  dp[4] = 1;
  dp[5] = 1;


  for (int i = 6; i <= n; i++) {

    if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) {
      dp[i] = 1;
    }

    else {
      dp[i] = 0;
    }
  }

  if (dp[n] == 1) {
    printf("SK");
  }

  else {
    printf("CY");
  }
}