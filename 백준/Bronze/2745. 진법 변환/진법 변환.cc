#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    int b , sum = 0;
    char n[5];

    scanf("%s %d", n, &b);
    for (int i = 0 , j = strlen(n) ; i < strlen(n); i++ , j--) {
        if (n[i] >= 65) {
            sum += (n[i] - 55) * pow(b, j-1);
        }
        else {
            sum += (n[i] - 48) * pow(b, j-1);
        }
    }
    printf("%d", sum);

    return 0;
}