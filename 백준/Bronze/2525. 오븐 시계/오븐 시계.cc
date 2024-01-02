#include <stdio.h>

int main(void) {
  int  h, m, c, h_c=0;
  scanf("%d  %d",&h,&m);
  scanf("%d",&c);
  
  c=c+m;
  h_c=c/60;
  c=c%60;
  
  if(h+h_c>=24){
    printf("%d %d", h+h_c-24, c);
  }
  else{
    printf("%d %d", h+h_c, c);
  }
}