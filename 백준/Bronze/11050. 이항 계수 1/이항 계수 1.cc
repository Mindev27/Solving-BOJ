#include <stdio.h>

int hm(int n, int k){
  if (n==k || k==0)
    return 1;
  
  else {
    return hm(n-1,k-1) + hm(n-1,k);
  }

}

int main(void) {
  int a,b;
  scanf("%d %d", &a, &b);

  printf("%d", hm(a,b));
}