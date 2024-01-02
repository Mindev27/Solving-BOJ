#include<stdio.h>
int Min(int a, int b){ return a < b ? a : b; }
int main() {
	int i, j, n, d[100001]; 
    scanf("%d", &n);
	for (i = 0; i <= n; i++) d[i] = i;
	for (i = 2; i <= n; i++)
		for (j = 2; j*j <= i; j++)
			d[i] = Min(d[i], d[i - j*j] + 1);
	printf("%d", d[n]);
}
