#include <stdio.h>

//최솟값 함수
int min(int a, int b) {
  if (a == 0 || b == 0)
    return 0;
  else {
    return a > b ? b : a;
  }
}

int main(void) {
  int n, k, i, j;
  int coin[10001] = {0,};
  int dp[10001] = {0,};

      scanf("%d %d", &n, &k);

  for (i=1 ; i<=n ; i++)
    scanf("%d", &coin[i]);

  for (i=1 ; i<=k; i++)
		dp[i] = 200000;

	dp[0] = 0;
  
	for (i=1; i<=n; i++) {
    
		for (j=coin[i]; j<=k; j++) {
      
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
      
		}
	}

	if (dp[k] == 200000)
		printf("%d", -1);
    
	else
		printf("%d", dp[k]);
}