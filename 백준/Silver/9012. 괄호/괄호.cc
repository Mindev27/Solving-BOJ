#include <stdio.h>
#include <string.h>

int main(void){
  int n, i;
  char a[51];
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%s",&a);
    int p=0, j;
      
    for(j=0;j<strlen(a);j++){
      
      if(a[j]=='('){
        p++;
      }

      if(a[j]==')'){
        p--;
      }
      if(p<0){
        printf("NO\n");
        break;
      }
    }
    if(p==0){
        printf("YES\n");
    } 
    if(p>0){
      printf("NO\n");
    }
  }
}