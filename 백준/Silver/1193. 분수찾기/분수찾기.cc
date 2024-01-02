#include <stdio.h>

int main(void) {
  int n, cnt=1;
  scanf("%d", &n);

  while(n>cnt){
    n-=cnt;
    cnt++;
  }
  if(cnt%2==0){
    printf("%d/%d",n ,cnt-n+1);
  }
  else{
    printf("%d/%d",cnt-n+1, n);
  }
  
}