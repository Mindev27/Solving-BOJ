#include <stdio.h>

// 교환 함수 (swap)를 매크로로 변경하여 최적화
#define SWAP(a, b) \
  {                \
    int temp = (a); \
    (a) = (b);     \
    (b) = temp;    \
  }

int main(void) {
  int n, i, j, temp, max_candy, odd_idx = 0;
  int odd[1000] = {};

  scanf("%d", &n);
  
  max_candy = 0;
  
  for(i = 0; i < n; i++){
    scanf("%d", &temp);

    if(temp % 2 == 0)
      max_candy += temp;
      
    else
      odd[odd_idx++] = temp;
  }

  //odd 정렬
  for(i = 0; i < odd_idx; i++){
    for(j = 0; j < odd_idx-1; j++){     
      if(odd[j] < odd[j+1])
        SWAP(odd[j], odd[j+1]);
    }
  }

  int candy_idx;
  candy_idx = (odd_idx/2) * 2;

  for(i = 0; i < candy_idx; i++){
    max_candy +=odd[i];
  }

  printf("%d", max_candy);
}