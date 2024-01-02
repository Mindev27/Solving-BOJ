#include <stdio.h>

//Compiler version gcc  6.3.0

int main(){

  int n, student[31]={0};

  

  for(int i=0;i<28;i++){

    scanf("%d", &n);

    student[n]++;

  }

  for(int i=1;i<=30;i++){

    if(student[i]==0){

      printf("%d\n", i);

    }

  }

  

}