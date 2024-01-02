#include <stdio.h> //n 개면 n-1번 시행

int main(void) {
  int n, i, m[1000001]={0};
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    m[i]=i;
  } 

  int start=1, end=n;
  
  for(i=1;i<n;i++){
    start++;
    m[end+1]=m[start];
    end++;
    start++;
  }

  printf("%d", m[end]);
}
