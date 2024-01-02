#include <stdio.h>


int main(void) {
  int T, i;
  scanf("%d", &T);

  for(i=0;i<T;i++){

    int x1, x2, y1, y2, r1, r2;
    scanf("%d %d %d %d %d %d", &x1,&y1,&r1,&x2,&y2,&r2);

    int d_2= (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    int r_2= (r1+r2)*(r1+r2);
    
    if((r2-r1)*(r2-r1)<d_2 && d_2<r_2){
      printf("2\n");
    }

    else if(d_2==r_2){
      printf("1\n");
    }
    else if(d_2==(r2-r1)*(r2-r1) && d_2!=0){
      printf("1\n");
    }
    else if(d_2<(r2-r1)*(r2-r1) || d_2>r_2){
      printf("0\n");
    }
    else{
      printf("-1\n");
    }
      
  }
}