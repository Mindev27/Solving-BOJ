#include <stdio.h>

int han(int k){
  int arr[5]={};
  int i=0;
  
  while(k>0){
    arr[i]=k%10;
    i++;
    k/=10;
  }

  if(i==1){

    return 1;
  }

  else if(i==2){

    return 1;
  }

  else if(i==3){
    
    if(arr[0]+arr[2]==2*arr[1]){
      return 1;
    } 

    else {
      return 0;
    }
  }

  else{
    
    if(arr[0]+arr[2]==2*arr[1] && arr[1]+arr[3]==2*arr[2]){
      return 1;
    }
    
    else {
      return 0;
    }
  }
}

int main(void) {
  int i,n,hansu=0;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    hansu+=han(i);
  }
  printf("%d",hansu);
  return 0;
}