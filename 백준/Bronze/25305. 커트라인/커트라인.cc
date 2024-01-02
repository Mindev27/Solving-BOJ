#include <stdio.h>

int main(void) {
  int i, j, n, k, arr[1001]={}, temp, flag;

  scanf("%d %d",&n, &k);
  
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  for(i=0;i<n;i++){
    flag=0;
      
    for(j=0;j<n-1;j++){
      
      if(arr[j]<arr[j+1]){
      
      temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1]=temp;
      flag=1;
      }
    }
    
    if(flag==0){
      break;
    }
  }
  
  printf("%d",arr[k-1]);
}