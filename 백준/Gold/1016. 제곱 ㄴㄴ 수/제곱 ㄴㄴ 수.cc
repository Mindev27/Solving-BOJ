#include <stdio.h>
#include <math.h>

int number[1000001];

int main(){
  long long min, max;
  long i, j, sqare;
  
  scanf("%lld %lld", &min, &max);
  
  int root, cnt = 0;
  root = (int)(sqrt(max));
  
  for (i = 2; i <= root; i++){
    
      sqare = i*i;
      
      for (j = sqare * ((min - 1) / sqare + 1) ; j <= max; j += sqare){
        number[j-min]++;
      }
  }
  
  for (i = 0; i < (max-min +1); i++){
    number[i] && cnt++;
  }
    
  printf("%d\n", max-min-cnt +1);
}