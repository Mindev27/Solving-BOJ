#include <stdio.h>

int IsSix(int k){
  int six=0;
  while(k>0){

    if(k%10==6){
      six++;
    }
    else{
      six=0;
    }

    k=k/10;

    if(six==3){
      return 1;
    }
  }
  return 0;
  
}

int main(void){
  
  int n, i=0, cnt=0;
  scanf("%d",&n);

  while(cnt!=n){
    i++;
    cnt = cnt + IsSix(i);
  
  }
  printf("%d",i);
}