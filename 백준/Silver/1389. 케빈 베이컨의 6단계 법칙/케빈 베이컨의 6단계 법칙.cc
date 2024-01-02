#include <stdio.h>
#define INF 9999999

//최솟값 반환 함수
int min(int a, int b){
  return a > b ? b : a;
}

int main(void) {
  int people, line, i, j, k, tempA, tempB, minValue, minIndex;
  int board[101][101] = {0,};
  int floyd[101][101] = {0};
  int minBacon[101] = {0,};

  scanf("%d %d", &people, &line);

  //연결된 정보를 2차원배열에 저장
  for(i = 0; i < line; i++){ 
    scanf("%d %d", &tempA, &tempB);
    board[tempA][tempB] = 1;
    board[tempB][tempA] = 1;
  }

  //floyd초기값 설정
  for(i = 1; i <= people; i++){
    for(j = 1; j <= people; j++){
      if(board[i][j]) floyd[i][j] = 1;
      else if(i == j) floyd[i][j] = 0;
      else floyd[i][j] = INF;
    }
  }

  //플로이드-워셜 ㄱㄱ팡 (k가 중간 노드)
  for(k = 1; k <= people; k++){
    for(i = 1; i <= people; i++){
      for(j = 1; j <= people; j++){
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
      }
    }
  }

  //케빈 베이컨 수 저장
  for(i = 1; i <= people; i++){
    for(j = 1; j <= people; j++){
      minBacon[i] += floyd[i][j];
    }
  }

  //최솟값 찾기
  minValue = minBacon[1];
  minIndex = 1;
  for(i = 1; i <= people; i++){
    if(minValue > minBacon[i]){
      minValue = minBacon[i];
      minIndex = i;
    }
  }

  printf("%d", minIndex);
}