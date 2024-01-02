#include <stdio.h>
#define SIZE 901

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int temp, i, j, n;
    
  int x[SIZE], y[SIZE], idx[SIZE];

  scanf("%d", &n);
  for(i = 0; i < 3*n; i++){
    scanf("%d %d", &x[i], &y[i]);
  }

  for(i = 0; i < 3*n; i++)
    idx[i] = i+1;
  
  for(i = 0; i < 3*n - 1; i++){
    
    for(j = 0; j < 3*n - 1; j++){
      
      if(x[j] > x[j+1]){
        swap(&x[j], &x[j+1]);
        swap(&y[j], &y[j+1]);
        swap(&idx[j], &idx[j+1]);
        
      } 
      
      else if(x[j] == x[j+1] && y[j] > y[j+1]){
        swap(&x[j], &x[j+1]);
        swap(&y[j], &y[j+1]);
        swap(&idx[j], &idx[j+1]);
      }
    }
  }
  
  for(i = 0; i < 3*n; i++){
    printf("%d ", idx[i]);

    if((i+1) % 3 == 0) printf("\n");
  }
}