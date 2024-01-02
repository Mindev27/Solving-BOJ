#include <stdio.h>

int main(){
  int a,i, n=0;
  for(i=0;i<5;i++){
    scanf("%d", &a);
    n+=((a%10)*(a%10))%10;
  }
  printf("%d",n%10);
}


