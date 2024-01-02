#include <stdio.h>

//킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
int main(void) {
  int chess[]={1,1,2,2,2,8};
  int dong[6]={0};

  for(int i=0;i<6;i++){
    scanf("%d",&dong[i]);
  }
  for(int i=0;i<6;i++){
    printf("%d ",chess[i]-dong[i]);
  }
}