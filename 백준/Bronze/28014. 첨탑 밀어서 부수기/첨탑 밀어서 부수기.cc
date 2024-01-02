#include <stdio.h>

int main(void) {
  int n, cnt = 0, preTower, nextTower;
  

  scanf("%d", &n);
  
  scanf("%d", &preTower);

  for(int i=0; i<n-1 ; i++){
    scanf("%d", &nextTower);

    if(preTower <= nextTower){
      cnt++;
    }
    preTower = nextTower;
  }


  printf("%d", cnt+1);
  
}