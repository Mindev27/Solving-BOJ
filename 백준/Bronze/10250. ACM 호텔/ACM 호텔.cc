#include <stdio.h>

int main(void) {
  
  int t, i;

  scanf("%d", &t);

  for(i=0;i<t;i++){

    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    
    if(n<=h){
      printf("%d\n", 100*n+1);
    }

    else{
      if(n%h==0){
        printf("%d\n",h*100+n/h);
      }
      else{
        printf("%d\n", 100*(n%h)+(n/h+1));
      }
   
    }
  }

}
