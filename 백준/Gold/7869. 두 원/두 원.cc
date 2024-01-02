#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238

void swap(int a, int b){
  int temp;

  temp = a;
  a = b;
  b= temp;
}

int main(void) {
  double x1, y1, r1, x2, y2, r2;

  scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2); 

  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  
  if(r1 < r2){
    swap(r1, r2);
    swap(x1, x2);
    swap(y1, y2);
  }
  if(r1 + r2 <= distance){ //두원이 안겹치면
    printf("0.000");
  }
  //한 원이 안에 들어있을때
  
  else if(r2 + distance <= r1){ 
    printf("%.3lf", r2 * r2 * PI); 
  }
  
  else{ // 삼각함수로 구하기 (호도법)
    double A = acos((r1*r1 + distance*distance - r2*r2) / (2*r1*distance));
    double B = acos((r2*r2 + distance*distance - r1*r1) / (2*r2*distance));

    double S1 = r1 * r1 * A - r1 * r1 * sin(2*A)/2;
    double S2 = r2 * r2 * B - r2 * r2 * sin(2*B)/2;

    printf("%.3lf", S1 + S2);
  }
  
}