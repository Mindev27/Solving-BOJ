#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int DP[103][100003];
int w[103];
int v[103];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - w[i] >= 0)
                DP[i][j] = MAX(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    printf("%d\n", DP[n][k]);

    return 0;
}
