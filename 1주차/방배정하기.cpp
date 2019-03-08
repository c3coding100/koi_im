#include <stdio.h>

int main()
{
    int a, b, c, n;
    int i, j, k;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    for (i = 0; i <= n / a; i++) {
        for (j = 0; j <= n / b; j++) {
            for (k = 0; k <= n / c; k++) {
                if (a * i + b * j + c * k == n) {
                    printf("1");
                    return 0;
                }
            }
        }
    }
    printf("O");
    return 0;
}
