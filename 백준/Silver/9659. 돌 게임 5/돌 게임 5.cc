#include <stdio.h>

int main(void) {
  long long int n;

  scanf("%lld", &n);

  if(n % 2 == 0){
    printf("CY");
  }
  else{
    printf("SK");
  }
}