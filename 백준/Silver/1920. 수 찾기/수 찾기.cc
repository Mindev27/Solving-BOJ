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
  int n, m, i, num, data[100001]={0};
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d", &data[i]);
  }
  
  qsort(data, n, sizeof(int), compare);
  
  scanf("%d", &m);
  
  for(i=0;i<m;i++){
    scanf("%d", &num);
    printf("%d\n",binsearch(data, n, num));
  }
}

int binsearch(int data[], int n, int key){ //이진탐색
  int low=0, high=n-1;
  int mid;
  
  while(low<=high){
    mid = (low+high)/2;
    if(key==data[mid]){
      return 1;
    }
    else if(key<data[mid]){
      high = mid-1;
    }
    else if(key>data[mid]){
      low = mid+1;
    }  
  }
  return 0;
}