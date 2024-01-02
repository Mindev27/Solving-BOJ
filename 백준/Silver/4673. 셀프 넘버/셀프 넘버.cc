#include <stdio.h>

int d(int n){
  int sum=n;
  while(n>0){
    sum += n%10;
    n = n/10;
  }
  
  return sum;
}

int main(void) {
  int num=0;

  int arr[10003]={};
  

  for(int i=1;i<=9999;i++){
    num=d(i);
    if(num<=10000){
      arr[num]=1;
    }
  }


  for(int j=1;j<=9999;j++){
    if (arr[j]!=1){
      printf("%d\n",j);
    }
  }
  
}