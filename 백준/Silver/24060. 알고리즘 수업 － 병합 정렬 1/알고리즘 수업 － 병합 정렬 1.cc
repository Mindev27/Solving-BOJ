#include <stdio.h>

int mergesort(int data[], int p, int r);
int merge(int data[],int p, int q, int r);

int data[500001]={}, temp[500001]={};
int cnt=0, k, K;

int mergesort(int data[], int p, int r){
  if(p<r){
    int k = (p+r)/2;
    mergesort(data, p, k);
    mergesort(data, k+1, r);
    merge(data, p, k, r);
  }
  return 0;
}

int merge(int data[], int p, int q, int r){
  int i = p, j = q+1, t = 1;
  while(i <= q && j <= r){
    
    if(data[i] <= data[j]){
      
      cnt++;
      if(cnt==K) k=data[i];
      
      temp[t++] = data[i++];
    }
    else {
      
      cnt++;
      if(cnt==K) k=data[j];
      
      temp[t++] = data[j++];
      }
  }
  
  while(i <= q){
    
    cnt++;
    if(cnt==K) k=data[i];
    
    temp[t++] = data[i++];
  }
  
  while(j <= r){
    
    cnt++;
    if(cnt==K) k=data[j];
    
    temp[t++] = data[j++];
  }
  
  i = p;
  t = 1;
  
  while(i<=r){
    data[i++] = temp[t++];
  }
  return 0;
}


int main(void) {
  int A;
  scanf("%d %d", &A, &K);

  for(int i=0;i<A;i++){
    scanf("%d", &data[i]);
  }

  mergesort(data, 0, A-1);

  if(cnt<K) 
    printf("-1");
  else 
    printf("%d", k);
    
}