#include <stdio.h>

long long max = 0, min = 1, max_length = 0, mid;
int k, n, cnt, i, lan[10000] = {};

int main(void) {

  scanf("%d %d", &k, &n);

  for (i = 0; i < k; i++) {

    scanf("%d", &lan[i]);

    if (lan[i] > max) {
      max = lan[i];
    }
  }

  while (min <= max) {
    cnt = 0;
    mid = (max + min) / 2;
    
    for (i = 0; i < k; i++) {
      cnt += lan[i] / mid;
    }

    if (cnt >= n) { //개수가 많거나
      min = mid + 1;
      if (max_length < mid) {
        max_length = mid;
      }
    } else { //개수가 부족하다면
      max = mid - 1;
    }
  }

  // yes, no의 경계값이라면 답 출력
  printf("%lld", max_length);
}