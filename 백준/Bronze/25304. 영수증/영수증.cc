#include <stdio.h>

//Compiler version gcc  6.3.0

int main(){

  int X, n, price, amount, t, total=0;

  

  scanf("%d",&X);

  scanf("%d",&n);

  

  for(int i=0;i<n;i++){

    scanf("%d %d", &price, &amount);

    t = price * amount;

    total=total + t;

  } 

  

  if(X==total){

    printf("Yes");

  }

  else{

    printf("No");

  }

}