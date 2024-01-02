#include <stdio.h>

int main(void) {
  int n, i, sum = 1;

  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    sum += 3 * i + 1;

    if(sum > 45678){
      sum = sum % 45678;
    }
  }

  printf("%d", sum);
}