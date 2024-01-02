#include <stdio.h>
#define INF 999999999

int min(int a, int b){
  return a > b ? b : a;
}

int main(void) {
  int n, m, k, i, j, tempA, tempB, tempCost;
  int board[101][101] = {0,};
  int floyd[101][101] = {0,};

  scanf("%d", &n);
  scanf("%d", &m);

  for(i = 0; i < m; i++){
    scanf("%d %d %d", &tempA, &tempB, &tempCost);

    //초기값 입력
    if(board[tempA][tempB] == 0){
      board[tempA][tempB] = tempCost;
    }

    else{
      if(board[tempA][tempB] > tempCost){
        board[tempA][tempB] = tempCost;
      }
    }
  }

  //floyd배열에 초기값 설정
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(i == j) floyd[i][j] = 0;
      else if(board[i][j]) floyd[i][j] = board[i][j];
      else floyd[i][j] = INF;
    }
  }

  //플로이드-워셜 알고리즘
  for(k = 1; k <= n; k++){
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
      }
    }
  }
  
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(floyd[i][j] == INF)
        printf("0 ");
      else
        printf("%d ", floyd[i][j]);
    }
    printf("\n");
  }
}