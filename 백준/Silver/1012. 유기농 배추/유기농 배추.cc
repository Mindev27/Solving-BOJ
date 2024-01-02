#include <stdio.h>
#include <string.h>
int m,n,t,j, k;
int field[51][51]={};
    
int dfs(int x, int y){  
  field[x][y]=0; 

  if(x+1<=m && field[x+1][y]==1) dfs(x+1,y);
  if(x-1>=0 && field[x-1][y]==1) dfs(x-1,y);
  if(y+1<=n && field[x][y+1]==1) dfs(x,y+1);
  if(y-1>=0 && field[x][y-1]==1) dfs(x,y-1);
  return 0;
}

int main(void) {
  int T, i;
  scanf("%d",&T);

  for(i=0;i<T;i++){

    memset(field,0,sizeof(field));
    scanf("%d %d %d",&m,&n,&t);

    for(j=0;j<t;j++){
      int a,b;
      scanf("%d %d",&a,&b);
      field[a][b]=1;    
    }
    int cnt=0;
    
    for(j=0;j<=m;j++){
      for(k=0;k<=n;k++){
        if(field[j][k]==1){
          
          dfs(j,k);      
          cnt+=1;
        }
        
      }
    }
    printf("%d\n",cnt);
  }
}
