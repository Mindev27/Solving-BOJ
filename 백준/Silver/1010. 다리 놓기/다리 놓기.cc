#include <stdio.h>

int main(void) {
  
  int T, n, m, Combination;
  
  scanf("%d", &T);
  
  for (int i = 0; i < T; i++) {
    
    Combination = 1;
    scanf("%d %d", &n, &m);

    for (int j = 0; j < n; j++) {
      Combination *= (m - j);
      Combination /= (j + 1);
    }
    printf("%d\n", Combination);
  }
}