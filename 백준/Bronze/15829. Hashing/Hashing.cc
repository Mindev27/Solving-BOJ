#include <stdio.h>
#define M 1234567891

int main() {
  int len, i;
  long long value = 0, R = 1;
  
  char str[51];

  scanf("%d %s", &len, str);

  for (i = 0; i < len; i++) {
    
    value = (value + (str[i] - 'a' + 1) * R) % M;
    
    R = (R * 31) % M;
  }

  printf("%lld\n", value);
}