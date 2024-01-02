#include <stdio.h>

int main(void) {
  int i, j, arr[10][10]={0}, max=0, a, b;
  
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      
      scanf("%d",&arr[i][j]);

      if(max<=arr[i][j]){
        max=arr[i][j];
        a=i;
        b=j;
      }
    }
  }
  printf("%d\n%d %d", max, a, b);
  
}