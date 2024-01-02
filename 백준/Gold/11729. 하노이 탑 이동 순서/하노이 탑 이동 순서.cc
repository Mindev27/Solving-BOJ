#include <stdio.h>

void Hanoi(int h, int s, int e) {

  if(h==1){

    printf("%d %d\n", s, e);

    return;

  }

  else{

    Hanoi(h-1, s, 6-e-s);

    printf("%d %d\n", s, e);

    Hanoi(h-1, 6-e-s, e);

    return;

  }

}

int main(void) {

  int n,cnt=1;

  scanf("%d", &n);

  for(int i=0 ; i<n ; i++){

    cnt=cnt*2;

  }

  printf("%d\n",cnt-1);

  Hanoi(n,1,3);

  return 0;

  }