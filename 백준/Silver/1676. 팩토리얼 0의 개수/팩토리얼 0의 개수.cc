#include <stdio.h>

int main(void) {
  int n, cnt_five, cnt_two, five = 5, two = 2;

  scanf("%d", &n);

  cnt_five = 0;
  cnt_two = 0;

  while (n >= five) {
    cnt_five += n / five;

    five *= 5;
  }

  while (n >= two) {
    cnt_two += n / two;

    two *= 2;
  }

  if (cnt_five > cnt_two)
    printf("%d", cnt_two);
  else
    printf("%d", cnt_five);
}