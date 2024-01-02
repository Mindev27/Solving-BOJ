#include <stdio.h>

int pyta(long long int a,long long int b,long long int c){

  if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b){
    return 1;
  }
  else{
    return 0;
  }
}

int main(void){
  long long int x,y,z;
 
  while(1){

    scanf("%lld %lld %lld", &x, &y, &z);
    if(x==0 && y==0 && z==0){
      break;
    }
    
    if(pyta(x,y,z)){
      printf("right\n");
    }
      
    else{
      printf("wrong\n");
    }
    
    
  }
}