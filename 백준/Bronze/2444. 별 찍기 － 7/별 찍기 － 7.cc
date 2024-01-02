#include <stdio.h>

int main(void) {
  int n, i, j;

  scanf("%d", &n);

  //공백은 (n-1)부터 0까지 1씩감소
  //별은 (2 * 1 - 1)개부터 (2 * (n-1) - 1)까지 2씩증가

  //윗부분 n줄 출력
  for(i = 0; i < n; i++){ //n번 반복하겠다

    //공백출력
    for(j = i; j < n - 1; j++){
      printf(" ");
    }

    //별 출력
    for(j = 0; j < 2 * i + 1; j++){
      printf("*");
    }

    //줄바꿈
    printf("\n");
  }

  //공백은 1부터 n-1까지 증가
  //별은 (2 * (n-1) - 1)부터 1까지 2씩 감소

  //아래부분 n-1줄 출력
  for(i = 0; i < n-1; i++){ //n-1번 반복하겠다

    //공백출력
    for(j = 0; j < i + 1; j++){
      printf(" ");
    }

    //별 출력
    for(j = (2 * i); j < (2 * (n-1) - 1); j++){
      printf("*");
    }

    //줄바꿈
    printf("\n");
  }
}