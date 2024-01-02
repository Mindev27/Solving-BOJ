#include <stdio.h> 

int main(void) {
  int a,b;
  scanf("%d %d", &a, &b);

  int x, y;
  
  if(a>=b)
    x=b, y=a;
  if(a<b)
    x=a, y=b;


  int temp;
  while(y%x!=0){
    temp = y%x;
    y=x;
    x=temp;
  }
  printf("%d\n%d", x, a*b/x);
}
