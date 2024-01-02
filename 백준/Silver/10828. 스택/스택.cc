#include <stdio.h>
#include <string.h>

int stack[100001];
int num, height=0;

void push(int k){
  stack[height] = num;
  height++;
}

void pop(){
  
  if(height==0)
    printf("-1\n");
    
  else{
    height--;
    printf("%d\n", stack[height]);
  } 
}

void size(){
  printf("%d\n", height);
}

void empty(){
  if(height==0)
    printf("1\n");
  else{
    printf("0\n");
  }
}

void top(){
  if(height==0)
    printf("-1\n");
    
  else{
    printf("%d\n", stack[height-1]);
  }
}


int main(void) {
  
  int i, n;

  char command[10];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%s",command);
    
    if (strcmp(command, "push") == 0){  
      scanf("%d", &num);
      push(num);
    }

    if (strcmp(command, "pop") == 0){
      pop();
    }

    if (strcmp(command, "size") == 0){
      size();
    }
    
    if (strcmp(command, "empty") == 0){
      empty();
    }

    if (strcmp(command, "top") == 0){
      top();
    }
  }
} 