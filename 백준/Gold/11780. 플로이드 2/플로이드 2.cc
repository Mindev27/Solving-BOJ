#include <stdio.h>
#include<string.h>
#define INF 999999999
#define SIZE 101

int info[SIZE][SIZE] = {0,};
int stack[101] = {};

void Path(int a, int b){
  
  if(info[a][b] == -1){
    printf("0\n");
  }
    
  else{
    int s = 0;

    stack[s++] = a;

    while(a != b){
      a = info[a][b];
      stack[s++] = a;
    }

    printf("%d ", s);
    for(int c = 0; c < s; c++){
      printf("%d ", stack[c]);
    }
    printf("\n");
  }
}
int main(void) {
  int n, m, k, i, j, tempA, tempB, tempCost;
  int floyd[SIZE][SIZE] = {0,};
  
  memset(info,-1,sizeof(info)); //info배열 전체 -1로 초기화

  scanf("%d", &n);
  scanf("%d", &m);

  for(i = 0; i < m; i++){
    scanf("%d %d %d", &tempA, &tempB, &tempCost);

    //초기값 입력
    if(floyd[tempA][tempB] == 0){
      floyd[tempA][tempB] = tempCost;
      info[tempA][tempB] = tempB;
    }

    else{
      if(floyd[tempA][tempB] > tempCost){
        floyd[tempA][tempB] = tempCost;
        info[tempA][tempB] = tempB;
      }
    }
  }

  

  //floyd배열에 초기값 설정
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(floyd[i][j] == 0 && i != j) floyd[i][j] = INF;
    }
  }

  //플로이드-워셜 알고리즘
  for(k = 1; k <= n; k++){
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
        
        if(floyd[i][j] > floyd[i][k] + floyd[k][j]){
          floyd[i][j] = floyd[i][k] + floyd[k][j];
          info[i][j] = info[i][k];
        }
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
  
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      Path(i, j);
    }
  }
}