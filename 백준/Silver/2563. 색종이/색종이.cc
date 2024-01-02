#include <stdio.h>

int main(void) {
  int a, b, n, paper[101][101]={0}, area=0;
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    
    scanf("%d %d",&a, &b);

    for(int j=a ; j<a+10 ; j++){
      for(int k=b ; k<b+10 ; k++){
        
        if(paper[j][k]==0){
          paper[j][k]++;
          area++;
        }
      }
    }
    
  }

  printf("%d",area);
}