#include <stdio.h>

int j, cnt, is_prime, min=0;

int P(int k){

  cnt=0;
  is_prime=0;

  for(j=1;j*j<=k;j++){
    
    if(k==1){
      is_prime=0;
      break;
    }

    if(k%j==0){
      cnt++;
    }
  }

  if(cnt==1){
    if(min==0){
        min=k;
    }
    is_prime=k;
  }

  return is_prime;
}

int main(void) {
  int M, N, i, n=0;
  scanf("%d", &M);
  scanf("%d", &N);

  for(i=M;i<=N;i++){

    n+=P(i);

  }
  if(min==0){
    printf("-1");
  }
  else{
      printf("%d\n%d", n, min);
  }

}