//묶음을 가져가는 게임으로 바꾸어서 해결
//선택권을 가지는 사람이 승리한다
//홀수번째에 처음으로 2이상 -> 선공 승
//짝수번째에 처음으로 2이상 -> 후공 승

#include <stdio.h>

int main(void) {

  int a, b, max, min, number, index, temp;

  while(1){
    scanf("%d %d", &a, &b);

    if(a == 0 && b == 0){
      break;
    }

    max = (a > b) ? a : b;
    min = (a > b) ? b : a;

    //새로운 게임으로 변경
    index = 0;
    
    while (1){

      index++;
      
      //number = 몇번 뺄수 있는지
      number = max / min;

      if(number > 1 && index % 2 == 1){
        printf("A wins\n");
        break;
      }
      
      if(number > 1 && index % 2 == 0){
        printf("B wins\n");
        break;
      }

      temp = max % min;
      max = min;
      min = temp;

      //끝까지 전부 1이라면
      if(min == 0){
        
        if(index % 2 == 1){
          printf("A wins\n");
          break;
        }
          
        else{
          printf("B wins\n");
          break;
        }
      }
    }   
  }
}