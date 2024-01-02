#include <stdio.h>

int main(void) {
  int i, j, arr[5], temp, avr;
  
  for(i=0;i<5;i++){
    scanf("%d",&arr[i]);
  }
  
  avr=(arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5; 
  
  for(i=0;i<5;i++){
    for(j=0;j<4;j++){
      if(arr[j]>arr[j+1]){
      
      temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1]=temp;
      
    }
    }
  }

  
  
  printf("%d\n%d",avr, arr[2]);
}