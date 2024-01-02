#include <stdio.h>

int main(void) {
  int n, i, maxLemon, temp;
  int lemon[200001] ={};

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &lemon[i]);
  }

  maxLemon = lemon[0] - n;
  
  for(i = 1; i < n; i++){
    temp = lemon[i] - (n - i);
    
    if(temp > maxLemon){
      maxLemon = temp;
    }
  }

  printf("%d", maxLemon);
}