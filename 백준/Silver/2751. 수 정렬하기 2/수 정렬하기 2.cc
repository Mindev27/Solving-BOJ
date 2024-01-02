#include <stdio.h>
#include <stdlib.h>

int binsearch(int data[], int n, int key);

int compare(const void *a, const void *b){
  
  int num1 = *(int *)a;
  int num2 = *(int *)b;

  if(num1<num2) 
    return -1;
  
  if(num1>num2) 
    return 1;
    
  return 0;
}

int main(void) {
  int n, i, data[1000001]={0};
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d", &data[i]);
  }
  
  qsort(data, n, sizeof(int), compare);
  

  
  for(i=0;i<n;i++){
    printf("%d\n",data[i]);
  }
}
