#include <stdio.h>

int main(void) {
  
  int dp[1005] = {0};

  int n;

  scanf("%d", &n);

  //초기 승리값 저장 1 = 선공 승 0 = 후공 승
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 0;
  dp[4] = 1;
  dp[5] = 1;

  for (int i = 6; i <= n; i++) {

    if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
      dp[i] = 0;
    }

    else {
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