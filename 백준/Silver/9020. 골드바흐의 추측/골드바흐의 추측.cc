#include <stdio.h>

int Prime(int k){ //소수면 1 반환, 아니면 0 반환

  int i,j, cnt=0;

  for(i=1;i*i<=k;i++){

    if(k%i==0){
      cnt++;
    }  
  }
  if(cnt==1){
    return 1;
  }
  else{
    return 0;
  } 
}

int main(void) {
  int T, i;
  scanf("%d", &T);

  for(i=0;i<T;i++){
    int n, j;

    scanf("%d", &n);

    n/=2;

    for(j=0;j<=n/2;j++){

      if(Prime(n-j)==1){
        if(Prime(n+j)==1){

          printf("%d %d\n",n-j,n+j);
          break;
        }
      }
    }
  }
}