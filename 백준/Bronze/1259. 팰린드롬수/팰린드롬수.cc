#include <stdio.h>

int p(int k){
  int a[6]={0}, cnt=0, pnum=0;
  
  while(k!=0){
    a[cnt] = k%10;
    
    k = k/10;
    cnt++;
  }

  int c = 1;
  
  for(int i=cnt-1 ; i>=0 ; i--){
    pnum += a[i]*c;
      c *= 10;
  }
  return pnum;
}

int main(){
  int n=1;
  
  while(n!=0){
    
    scanf("%d",&n);
    
    if(n==0){
      break;
    }
    else{
      if(n==p(n)){
        printf("yes\n");
      }
      else
        printf("no\n");
    }
  }
}