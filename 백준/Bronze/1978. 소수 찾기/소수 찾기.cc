#include <stdio.h>

int main(void) {
  int T, i, j, n, P=0;
  scanf("%d", &T);

  for(i=0;i<T;i++){

    scanf("%d", &n);

    int cnt=0;

    for(j=1;j*j<=n;j++){

      if(n==1){
      break;
      }

      if(n%j==0){
        cnt++;
      }
    }

    if(cnt==1){
      P++;
    }
  }

  printf("%d", P);
}