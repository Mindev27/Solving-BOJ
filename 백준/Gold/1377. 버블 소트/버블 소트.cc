#include <stdio.h>

void mergeSort(int data[], int index[], int p, int r);
void merge(int data[], int index[], int p, int q, int r);

int main(void) { 
  int list[500000]; 
  int index_list[500000];
  int n, i, max_cnt = 0;

  scanf("%d", &n);

  for(i=0 ; i<n ; i++){
    scanf("%d", &list[i]); 
    index_list[i] = i;
  }

  // for(i=0 ; i<n ; i++){
  //   printf("%d ", list[i]);
  // }
  // printf("\n");
  // for(i=0 ; i<n ; i++){
  //   printf("%d ", index_list[i]);
  // }
  // printf("\n");

  mergeSort(list, index_list, 0, n-1);

  // for(i=0 ; i<n ; i++){
  //   printf("%d ", list[i]);
  // }
  // printf("\n");
  
  // for(i=0 ; i<n ; i++){
  //   printf("%d ", index_list[i]);
  // }

  for(i=0 ; i<n ; i++){
    
    if(max_cnt < index_list[i] - i){
      
      max_cnt = index_list[i] - i;
    }
  }

  printf("%d", max_cnt + 1);
}

void mergeSort(int data[], int index[], int p, int r) {

  int q;

  if (p < r) {
    q = (p + r) / 2;
    mergeSort(data, index, p, q);
    mergeSort(data, index, q + 1, r);
    merge(data, index, p, q, r);
  }
}

void merge(int data[], int index[], int p, int q, int r) {

  int i = p, j = q + 1, k = p;
  int list_temp[500000], index_temp[500000];

  while (i <= q && j <= r) {
    
    if (data[i] <= data[j]){
      list_temp[k] = data[i];
      index_temp[k] = index[i];
      k++;
      i++;
    }    
    else{
      list_temp[k] = data[j];
      index_temp[k] = index[j];
      k++;
      j++;
    }  
  }

  while (i <= q){
    list_temp[k] = data[i];
    index_temp[k] = index[i];
    k++;
    i++;
  }

  while (j <= r){
    list_temp[k] = data[j];
    index_temp[k] = index[j];
    k++;
    j++;
  }
  
  for (int a = p; a <= r; a++){
    data[a] = list_temp[a];
    index[a] = index_temp[a];
  }
}

