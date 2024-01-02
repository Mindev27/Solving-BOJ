#include <stdio.h>

int main(void) {
  int i, j, n, m, inven, height, time, cnt_break, cnt_build, best_time, best_height = 0;
  int map[501][501] = {};

  scanf("%d %d %d", &n, &m, &inven);

  for(i=0 ; i<n ; i++){
    for(j=0 ; j<m ; j++){
      scanf("%d", &map[i][j]);
    }
  }
  
  best_time = 2147483647; //int 최댓값
  
  //브루트포스로 모든 높이에 대해 계산
  for(height=0 ; height<=256 ; height++){

    cnt_break = cnt_build = 0;
    //부숴야하는 개수와 깔아야하는 개수 계산
    for(i=0 ; i<n ; i++){
      for(j=0 ; j<m ; j++){
        
        if(height < map[i][j])
          cnt_break += map[i][j] - height;
        else
          cnt_build += height - map[i][j];
      }
    }
    
    //가능한지 여부와 최소시간 업데이트
    if(cnt_build <= cnt_break + inven){
      time = cnt_build + 2 * cnt_break;

      if(time <= best_time){
        best_time = time;
        best_height = height;
      }
    }
  }
  
  printf("%d %d", best_time, best_height);
}