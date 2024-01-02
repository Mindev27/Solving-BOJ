#include <stdio.h>

int main(void) {
  int n, i,j, find=1;
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    int sum=0;
    for(j=i;j>0;j=j/10){
      sum =sum + j%10;
    }
    if(i+sum==n){
      printf("%d",i);
      find=0;
      break;
    }
  }
  if(find){
    printf("0");
  }
}
