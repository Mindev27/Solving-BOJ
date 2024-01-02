#include <stdio.h>

int main(void) {
  
  int t, i;
  
  scanf("%d", &t);

  for(i=0;i<t;i++){

    long long int k, n, num=1;
    scanf("%lld", &k);
    scanf("%lld", &n);
    
    k+=1;

    int temp=k+n-1;

    while(temp>=k+1){
      num*=temp;
      temp--;
    
    }

    temp=n-1;

    while(temp>1){
      num/=temp;
      temp--;
   
    }

    printf("%lld\n", num);
  }
  
}
