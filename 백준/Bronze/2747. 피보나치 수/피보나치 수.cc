#include <stdio.h>

int memo[46] = {0,};

int fibo(int k){
  if(memo[k] != 0){
    return memo[k];
  }
  
  if(k == 1 || k == 2){
    return 1;
  }
    
  else{
    return memo[k] = fibo(k-1) + fibo(k-2);
  }
}
int main(void) {
  int n;

  scanf("%d", &n);

  printf("%d", fibo(n));
  
}