#include <stdio.h>

char win(int A[], int B[])
{
    for (int i = 4; i > 0; i--)
    {
        if (A[i] > B[i]) return 'A';
        if (A[i] < B[i]) return 'B';
    }
    return 'D';
}

int main()
{
    int N;
    int A[5], B[5];

    scanf("%d", &N);
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 1; j <= 4; j++)
            A[j] = B[j] = 0;

        int cnt, card;
        scanf("%d", &cnt);
        for (j = 0; j < cnt; j++)
        {
            scanf("%d", &card);
            A[card]++;
        }

        scanf("%d", &cnt);
        for (j = 0; j < cnt; j++)
        {
            scanf("%d", &card);
            B[card]++;
        }

        printf("%c\n", win(A, B));
    }

    return 0;
}
