#include <stdio.h>

int memo[41]={0,};


long long int f(long long int k){

  if(k==1 || k==2){

    memo[k]=1;
    return 1;

  }

  else if(memo[k]!=0){

    return memo[k];

  }

  else{

    return memo[k]=f(k-1) + f(k-2);

  }

}



int main(void) {
  int T, i;
  scanf("%d", &T);

  for(i=0;i<T;i++){
   
    int n;
    
    scanf("%d",&n);
    if(n==0){
      printf("1 0\n");
    }
    else if(n==1){
      printf("0 1\n");
    }
    else{
      printf("%lld %lld\n", f(n-1), f(n));
    }
    
  }
}