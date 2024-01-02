#include <stdio.h>

int main(void) {
  int n, i, j, a[51][2]={};
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d", &a[i][0], &a[i][1]);
  }
  for(i=0;i<n;i++){
    int num=1;
    for(j=0;j<n;j++){
      if(a[i][0]<a[j][0] &&a[i][1]<a[j][1]){
        num++;
      }
    }
    printf("%d ",num);
  }
  
}