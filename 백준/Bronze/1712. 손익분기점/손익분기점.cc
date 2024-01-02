#include <stdio.h>

int main(void) {

  long long int a, b, c;

  int cnt;

  scanf("%lld %lld %lld",&a,&b,&c);

  

  if(b==c || b>c){

    printf("-1");

  }

    

  else{

    

    if(a<(c-b)){      

      cnt=1;

    }

    

    else {

      cnt=a/(c-b)+1;

    }

    printf("%d",cnt);

  }

}