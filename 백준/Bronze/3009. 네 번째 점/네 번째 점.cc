#include <stdio.h>

int main(void) {
  int a[3][3];

  scanf("%d %d",&a[0][0], &a[0][1]);
  scanf("%d %d",&a[1][0], &a[1][1]);
  scanf("%d %d",&a[2][0], &a[2][1]);

  if(a[0][0]==a[1][0]){
    printf("%d ",a[2][0]);
  }
  else if(a[1][0]==a[2][0]){
    printf("%d ",a[0][0]);
  }
  else{
    printf("%d ",a[1][0]);
  }

  if(a[0][1]==a[1][1]){
    printf("%d",a[2][1]);
  }
  else if(a[1][1]==a[2][1]){
    printf("%d",a[0][1]);
  }
  else{
    printf("%d",a[1][1]);
  }
}