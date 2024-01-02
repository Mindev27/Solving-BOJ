#include <stdio.h>
#include <string.h>

int queue[100001];
int num, start = 0, end = 0;

void push(int k){
  queue[end] = num;
  end++;
}

void pop(){
  
  if(start == end && queue[start] == 0)
    printf("-1\n");
    
  else{
    printf("%d\n", queue[start]);
    queue[start] = 0;
    start++;
  } 
}

void size(){
  
  if(start == end && queue[start] == 0)
    printf("0\n");
    
  else if(start == end)
    printf("1\n");
    
  else
    printf("%d\n", end - start);
}

void empty(){
  
  if(start == end && queue[start] == 0)
    printf("1\n");
    
  else
    printf("0\n");
}

void front(){
  
  if(start == end && queue[start] == 0)
    printf("-1\n");

  else
    printf("%d\n", queue[start]);
}

void back(){
  if(start == end && queue[start] == 0)
    printf("-1\n");

  else if(start == end)
    printf("%d\n", queue[end]);

  else
    printf("%d\n", queue[end-1]);
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

    if (strcmp(command, "pop") == 0)
      pop();

    if (strcmp(command, "size") == 0)
      size();
    
    if (strcmp(command, "empty") == 0)
      empty();

    if (strcmp(command, "front") == 0)
      front();

    if (strcmp(command, "back") == 0)
      back();
  }
} 