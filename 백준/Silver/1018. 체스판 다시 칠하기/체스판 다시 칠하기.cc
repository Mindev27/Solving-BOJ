#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  int n, n_1;

  (void)scanf("%d %d", &n, &n_1);

  int count_b = 0;
  int count_w = 0;
  int sum = 1000;
  int c_count = 0;

  char ch[n][n_1];
  char ch_b[8][8];
  char ch_w[8][8];
  // 입력받기
  for (int i = 0; i < n; i++) {
    (void)scanf("%s", ch[i]);
  }
  // B시작
  ch_b[0][0] = 'B';
  c_count = 0;
  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      if (c_count == 0) {
        ch_b[i][k] = 'B';
        if (k != 7) {
          c_count = 1;
        }

      } else if (c_count == 1) {
        ch_b[i][k] = 'W';

        if (k != 7) {
          c_count = 0;
        }
      }
    }
  }

  
  ch_w[0][0] = 'W';
  c_count = 1;

  for (int i = 0; i < 8; i++) {
    for (int k = 0; k < 8; k++) {
      if (c_count == 0) {
        ch_w[i][k] = 'B';
        if (k != 7) {
          c_count = 1;
        }

      } else if (c_count == 1) {
        ch_w[i][k] = 'W';

        if (k != 7) {
          c_count = 0;
        }
      }
    }
  }

  ///////////////////////////////////////////////
  
  
  for (int i = 0; i <= n - 8; i++) {
    for (int k = 0; k <= n_1 - 8; k++) {
      count_b = 0;
      count_w = 0;
      for (int p = 0; p < 8; p++) {
        for (int q = 0; q < 8; q++) {
          if (ch[i + p][k + q] != ch_b[p][q]) {
            count_b++;
          }
          if (ch[i + p][k + q] != ch_w[p][q]) {
            count_w++;
          }
        }
      }

      
      if ((count_b <= count_w && sum >= count_b))
        sum = count_b;
      else if ((count_w <= count_b && sum >= count_w))
        sum = count_w;
    }
  }
  printf("%d", sum);
  return 0;
}
