#include <stdio.h>
#include <math.h>

int main(void) {
  int num, x ,y, count, pivot;

  scanf("%d %d %d", &num, &y, &x);
  count = 0;


  while(num>=0){
    num--;
    pivot = (int)pow(2, num);

    //왼쪽위에 해당할때
    if(x < pivot && y < pivot){
      continue;
    }

    //오른쪽위에 해당할때
    else if(x >= pivot && y < pivot){
      
      count += 1 * ((int)pow(pivot,2));
      
      x -= pow(2, num);
      
    }

    //왼쪽아래에 해당할때
    else if(x < pivot && y >= pivot){
      
      count += 2 * ((int)pow(pivot,2));
      
      y -= pivot;
      
    }

    //오른아래에 해당할때
    else{
      
      count += 3 * ((int)pow(pivot,2));
      
      x -= pivot;
      y -= pivot;
      
    }
  }

  printf("%d" ,count);
}