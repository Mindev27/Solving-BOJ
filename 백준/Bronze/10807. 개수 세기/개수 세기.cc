#include <stdio.h>

//Compiler version gcc  6.3.0

int main(){

  int N, key, p=0, num[101]={0};

  

  scanf("%d", &N);

  

  for(int i=0;i<N;i++){

    scanf("%d ", &num[i]);

  }

  

  scanf("%d", &key);

  

  for(int i=0;i<N;i++){

    if(key==num[i]){

      p++;

    }

  }

  printf("%d",p);

}