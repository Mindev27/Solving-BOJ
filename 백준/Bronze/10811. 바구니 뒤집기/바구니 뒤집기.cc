#include <stdio.h>

int main(void) {
  int arr[101] = {};
  int temp[101] = {};
  int n, m, i, j, start, end;

  scanf("%d %d", &n, &m);

  for (i = 1; i <= n; i++) {
    arr[i] = i;
  }

  for (i = 0; i < m; i++) {
    
    scanf("%d %d", &start, &end);

    for (j = start; j <= end; j++) {
      temp[j] = arr[j];
    }
    for (j = start; j <= end; j++) {
      arr[j] = temp[end - (j - start)];
    }
  }

  for (j = 1; j <= n; j++) {
    printf("%d ", arr[j]);
   }
}