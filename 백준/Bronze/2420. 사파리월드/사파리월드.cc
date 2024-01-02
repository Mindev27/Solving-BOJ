#include <stdio.h>

int main(void) {
  long long int a, b, diff;

  scanf("%lld %lld", &a, &b);

  diff = a - b;

  if(diff<0){
    diff = -diff;
  }

  printf("%lld", diff);
}