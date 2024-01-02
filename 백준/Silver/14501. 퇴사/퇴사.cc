#include <stdio.h>

int n, p, T[17], P[17], max=0;

void consult(int t, int p){
  if(t > n) return;
  
  if(p > max) max = p;
  
  if(t == n) return;
  
  consult(t + T[t], p + P[t]);
  consult(t+1, p);
}

int main(void) {
  
  int i;
  
  scanf("%d", &n);

  for(i=0 ; i<n ; i++){
    scanf("%d %d", &T[i], &P[i]);
  }

  consult(0, 0);
  
  printf("%d", max);
}

