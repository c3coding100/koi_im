#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);

    if (N % 10)
        printf("-1");
    else
        printf("%d %d %d", N / 300, (N % 300) / 60, (N % 60) / 10);

    return 0;
}
