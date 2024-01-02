#include <stdio.h>

long long max = 0, min = 1, max_length = 0, mid;
long long int k, n, cnt, i, tree[1000001] = {};

int main(void) {

  scanf("%lld %lld", &k, &n);

  for (i = 0; i < k; i++) {

    scanf("%lld", &tree[i]);

    if (tree[i] > max) {
      max = tree[i];
    }
  }

  while (min <= max) {
    cnt = 0;
    mid = (max + min) / 2;

    for (i = 0; i < k; i++) {
      if (tree[i] > mid) {
        cnt += tree[i] - mid;
      }
    }

    if (cnt >= n) {
      min = mid + 1;
      if (max_length < mid) {
        max_length = mid;
      }
    } else {
      max = mid - 1;
    }
  }

  printf("%lld", max_length);
}