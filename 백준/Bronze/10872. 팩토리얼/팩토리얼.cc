#include <stdio.h>

int facto(int k){
  if(k==1 || k==0){
    return 1;
  }
  else{
    return k * facto(k-1);
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  printf("%d",facto(n));
}