#include <stdio.h>

int main(void) {
  int iInputA, iInputB;
  int iCom, iLine, i, idx, end = 0;
  int board[101][101] = {0,};
  int virus[101] = {0,};
  int queue[101] = {0,};
  int visited[100000] = {0,};
  
  scanf("%d", &iCom);
  scanf("%d", &iLine);

  for(i = 0; i < iLine; i++){ //연결된 컴퓨터 입력
    scanf("%d %d", &iInputA, &iInputB);
    board[iInputA][iInputB] = 1;
    board[iInputB][iInputA] = 1;
  }

  // //board 배열 체크
  // for(int j = 1; j <= iCom; j++){
  //   for(i = 1; i <= iCom; i++){
  //     printf("%d ",board[j][i]); 
  //   }
  //   printf("\n");
  // }

  //1과 붙어있는 숫자 큐에 추가
  for(i = 1; i <= iCom; i++){
    if(board[1][i] == 1){ //연결되어 있다면
      board[1][i] = 0; //그 죄표를 0으로 변경
      // printf("(%d, %d)\n",1, i);
      virus[i] = 1;
      queue[end++] = i; //큐에 추가
    }
  }

  // printf("%d\n", end);
  
  //큐가 빌때까지 반복
  while(end > 0){
    
    // for(i = 0; i < iCom; i++){
    //   printf("%d ",queue[i]);
    // }
    // printf("\n");

    idx = queue[end - 1]; //큐의 끝값 저장
    // printf("idx : %d\n", idx);
    queue[end - 1] = 0;
    end--;
    
    if(visited[idx] == 0){ //방문한적이 없다면 실행
      
      for(i = 1; i <= iCom; i++){
        
        if(board[idx][i] == 1){ //연결되어 있다면
          
          board[idx][i] = 0; //그 죄표를 0으로 변경
          // printf("(%d, %d)\n",idx, i);
          virus[i] = 1;
          queue[end++] = i; //큐에 추가
          
        }
      }
    }
    visited[idx] = 1;//방문함을 표시
  }
  
  int cnt = 0; //감염된 개수
  
  for(i = 1; i <= iCom; i++){ //연결된 컴퓨터 입력
    if(virus[i] == 1){
      cnt++;
    }
  }
  if(cnt == 0){
    printf("0");
  }
  else{
    //1은 개수에서 제외
    printf("%d", cnt - 1);
  } 
}