#include <stdio.h>

int main(void) {
  
  int n,k, i, coin[101], d[10001]={0};
  scanf("%d %d",&n, &k);

  for(i=1 ; i<=n ; i++){
    scanf("%d", &coin[i]);
  }
  
  d[0]=1;
  
  for(int i=1;i<=n;i++){
    for (int j=1;j<=k;j++){
      if(j>=coin[i]){
        d[j]+=d[j-coin[i]];
      }
    }
  }
  printf("%d", d[k]);
}