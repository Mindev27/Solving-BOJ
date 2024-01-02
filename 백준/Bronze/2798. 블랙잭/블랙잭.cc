#include <stdio.h>

int main(void) {

  int T, black_n, i, j, k, max=0;

  int a[101]={};

  scanf("%d %d", &T, &black_n);

  

  for(i=0;i<T;i++){ 

    scanf("%d",&a[i]);

  }

  for(i=0;i<T;i++){

    for(j=0;j<T;j++){

      for(k=0;k<T;k++){

        if(i<j && j<k && a[i] + a[j] + a[k] <=black_n && a[i] + a[j] + a[k]>max){

          max=a[i] + a[j] + a[k];

        }

      }

    }

  }

  printf("%d", max);

}