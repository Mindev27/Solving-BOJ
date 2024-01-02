#include <stdio.h>

int main(){

  int n, m, start, end, i, num, sum = 0;

  int data[100001] = {0,};

  

  scanf("%d %d",&n, &m);

  

  for(i=1 ; i<=n ; i++){

    scanf("%d", &num);

    sum += num;

    data[i] = sum;

  }

  

  for(i=0 ; i<m ; i++){

    scanf("%d %d", &start, &end);

    printf("%d\n", data[end]-data[start-1]);

  }

}