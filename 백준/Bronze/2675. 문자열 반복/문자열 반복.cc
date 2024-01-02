#include <stdio.h>

#include <string.h>

int main(void){

  

  int t, n, i, j, k;

  

  scanf("%d", &t);

  

  for(i=0;i<t;i++){

    

    char a[20]={};

    scanf("%d", &n);

    scanf("%s", a);

    for(j=0;j<strlen(a);j++){

      for(k=0;k<n;k++){

        printf("%c",a[j]);

      }

    }

printf("\n");

    

  }

}