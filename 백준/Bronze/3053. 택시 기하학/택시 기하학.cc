#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void){
  
  long double r;
  scanf("%Lf",&r);
  printf("%Lf\n",r*r*M_PI);
  printf("%Lf",r*r*2);

}