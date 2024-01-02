#include <stdio.h>

int temp, n, i, iInput, num_cnt, heap[300000] = {};

//교환 함수
void swap(int *a, int *b){
  temp = *a;
  *a = *b;
  *b = temp;
}

//최대 힙 위에서 아래로 정리
int TopBottom_heap(int index){
  
  int leftChild = index * 2;
  int rightChild = index * 2 + 1;
  int biggest = index;

  // 왼쪽 자식노드와 비교
  if (leftChild < num_cnt && heap[leftChild] > heap[biggest])
    biggest = leftChild;

  // 오른쪽 자식노드와 비교
  if (rightChild < num_cnt && heap[rightChild] > heap[biggest])
    biggest = rightChild;

  // 현재 노드가 자식노드보다 작다면 교환하고 재귀적으로 호출
  if (biggest != index){
    swap(&heap[index], &heap[biggest]);
    TopBottom_heap(biggest);
  }
  return 0;
}

//가장 큰 수 출력
int print_max_heap(){

  //힙이 비어있다면 0출력
  if(num_cnt == 1){
    printf("0\n");
    return 0;
  }
  
  //가장 마지막 노드와 처음 노드 변경
  num_cnt--;
  swap(&heap[1], &heap[num_cnt]);
  printf("%d\n", heap[num_cnt]);
  heap[num_cnt] = 0;

  //1번째 인덱스부터 힙을 다시 정리
  TopBottom_heap(1);
  
  return 0;
}

//아래에서 위쪽으로 정렬
int BottomTop_heap(int index){
  
  //부모노드가 없다면
  if(index == 1){
    return 0;
  }

  //부모노드와 비교
  if(heap[index] > heap[index / 2]){
    swap(&heap[index], &heap[index / 2]);
    BottomTop_heap(index / 2);
  }
  
  return 0;
}

int main(void) {
  
  scanf("%d", &n);
  num_cnt = 1;

  for(i = 0; i < n; i++){
    scanf("%d", &iInput);

    if(iInput == 0){
      print_max_heap();
    }
    else{
      heap[num_cnt] = iInput;
      BottomTop_heap(num_cnt);
      num_cnt++;
    }
  }
}