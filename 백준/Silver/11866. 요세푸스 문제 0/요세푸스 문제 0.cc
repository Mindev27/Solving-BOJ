#include <stdio.h>

int main(void) {
  int yosepus[1005] = {};
  int killed[1005] = {};

  int reader = 0, arr_num = 0, N, K;

  scanf("%d %d", &N, &K);

  int human_num = N, start = 1, end = N+1, i;

  //인원수만큼 배열에 입력
  for(i=1 ; i<=N ; i++){
    yosepus[i] = i;
  }

  //모두 제거될때까지 반복
  while(human_num > 0){

    reader += K; //K만큼 뛰어넘기

    //끝을 넘으면 처음으로 돌리기
    while(reader >= end){
      reader -= human_num;
    }

    killed[arr_num] = yosepus[reader]; //죽은 번호 넣기
    arr_num++;

    //한칸씩 땡기기
    for(i = reader-1 ; i >= start ; i--){
      yosepus[i+1] = yosepus[i];
    }
    start++;
    human_num--;

  }

  printf("<");
  for(i=0 ; i<N-1 ; i++){
    printf("%d, ", killed[i]);
  }
  
  printf("%d>", killed[N-1]);

}