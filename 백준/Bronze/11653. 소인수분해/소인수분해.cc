#include <stdio.h>

int main(void) {
  int n, i, is_p=1;
  scanf("%d", &n);
  
  if(n!=1){

    while(is_p==1){

      is_p=0;

      for(i=2;i*i<=n;i++){
    
        if(n%i==0){
          is_p=1;
          printf("%d\n", i);
          n/=i;
          break;
        }

      }

    }
    printf("%d\n", n);   
  }
  
}