#include <stdio.h>

int main(void) {
  char a[101];
  int i, n, sum=0;
  scanf("%d",&n);  
  scanf("%s",a);

  for(i=0;i<n;i++){
    sum+=a[i]-'0';
  }
  
  printf("%d",sum);

  return 0;
}