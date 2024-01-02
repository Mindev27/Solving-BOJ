#include<stdio.h>

int main(){

  int a, b, num, n;

  

  scanf("%d %d %d", &a, &b, &n);

  

  for(int i=0 ; i<n ; i++){

    a = a % b;

    a = a * 10;

    num = a / b;

  }

  printf("%d", num);

}