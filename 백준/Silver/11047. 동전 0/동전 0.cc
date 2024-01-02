#include <stdio.h>

int main(void) {
  int n, k, cnt=0, index, coin[10] = {};

  scanf("%d %d", &n, &k);

  //배열에 입력
  for (int i = 0; i < n; i++) {
    scanf("%d", &coin[i]);
  }

  index = n - 1;
  while(k > 0){

    if(coin[index] > k){
        index --;
    }

    else{
        k -= coin[index];
        cnt++;
    }
  }
  
  printf("%d", cnt);
}