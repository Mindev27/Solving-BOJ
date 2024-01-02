#include <stdio.h>

int main(void) {
  int n, cnt=1, bee=6;
  scanf("%d", &n);
  
  if(n==1){
    printf("1");
  }
  
  else{
    n-=1;
    while(n>0){
      cnt+=1;
      n-=bee;
      bee+=6;
    }
    printf("%d", cnt);
  }
  
}
