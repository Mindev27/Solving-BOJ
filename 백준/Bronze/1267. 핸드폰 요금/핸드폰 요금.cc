#include <stdio.h>

int main(void) {

  int n, i, Y_sum=0, M_sum=0, time;

  scanf("%d",&n);

  for( i=1; i<=n ; i++){//오빠 바보

    scanf("%d",&time);

    Y_sum += ((time/30+1)*10); // 영식이 계산 끝
    M_sum += ((time/60+1)*15); // 민식이 계산 끝

  }

  if(Y_sum>M_sum){
    printf("M %d",M_sum);
  }
  else if(Y_sum<M_sum){
    printf("Y %d",Y_sum);
  }
  else if(Y_sum == M_sum){
    printf("Y M %d",Y_sum);
  }

}
