#include <stdio.h>

int main()
{
  int n, x, c = 0;

  scanf("%d", &n);

  int a[n];

  for(int i = 0; i < n; i++)
    {
      scanf("%d", &c);
      a[i] = c;
    }
  int max = a[0];
  int min = a[0];

  for(int i = 0; i < n; i++)
    {
      if(a[i] >= max)
      {
        max = a[i];
      }
      if(a[i] <= min)
      {
        min = a[i];
      }

    }

  printf("%d %d", min, max);


  return 0;
}