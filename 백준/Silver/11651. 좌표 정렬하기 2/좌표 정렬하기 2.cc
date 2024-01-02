#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

int compare(const void *a, const void *b) {

  //a의 자료형을 point의 포인터로 바꾸고 이 값을 얻기위해 *을 붙인다
  point A = *(point *)a;
  point B = *(point *)b;

  if (A.y > B.y) {
    return 1;
  } 
  
  else if (A.y == B.y) { //y좌표같다면
    if (A.x > B.x) {
      return 1;
      
    } 
    else {
      return -1;
    }
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  point *data;
  data = (point *)malloc(sizeof(point) * n); //포인터로 배열에 동적할당
  
  for (int i = 0; i < n; i++) {

    scanf("%d %d", &data[i].x, &data[i].y);
  }

  qsort(data, n, sizeof(point), compare);

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", data[i].x, data[i].y);
  }
  free(data);//동적할당 풀기
  return 0;
}