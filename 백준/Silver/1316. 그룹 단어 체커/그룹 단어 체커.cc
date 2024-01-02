
#include <stdio.h>
#include <string.h>

int main(void) {
  
  int n, i, j, num=0;
  char pre_str;
  scanf("%d", &n);
  
  for(i=0;i<n;i++){
    
    char str[101]={};
    int alpha[27]={0};
    
    scanf("%s",str);
    pre_str=str[0];

    alpha[(int)(pre_str)-97]=1;

    for(j=1;j<strlen(str);j++){
      
      if(alpha[str[j]-97]==1 && str[j]!= pre_str){
        num+=1;
        break;
      }

      pre_str=str[j];

      alpha[str[j]-97]=1;
      
      
      }
    
    }
  printf("%d",n-num);
}
