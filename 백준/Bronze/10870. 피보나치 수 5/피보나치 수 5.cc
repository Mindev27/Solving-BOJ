#include <stdio.h>

int memo[21]={0};

int fibo(int k){
  
  if(memo[k]!=0){
    return memo[k];
  }
    
  else if(k==0){
    memo[k]=0;
    return 0;
  }
  else if(k==1){
    memo[k]=1;
    return 1;
  }
  else{
    return memo[k]=fibo(k-2)+fibo(k-1);
  }
}

int main(void){
  
  int n;
  scanf("%d",&n);
  printf("%d",fibo(n));

  return 0;
}