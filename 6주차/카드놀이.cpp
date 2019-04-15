#include <cstdio>
#include <vector>
using namespace std;
int A[10];
int B[10];
int main(void)
{
    int i, j;
    for (i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < 10; i++) {
        scanf("%d", &B[i]);
    }

    int last_winner = -1;
    int A_score = 0;
    int B_score = 0;
    for (i = 0; i < 10; i++) {
        if (A[i] > B[i])
            A_score += 3, last_winner = 0;
        else if (A[i] < B[i])
            B_score += 3, last_winner = 1;
        else
            A_score ++, B_score ++;
    }

    printf("%d %d\n", A_score, B_score);

    if (A_score == B_score) {
        if (last_winner == -1)
            printf("D");
        else if (last_winner == 0)
            printf("A");
        else if (last_winner == 1)
            printf("B");
    } else if (A_score > B_score) {
        printf("A");
    } else {
        printf("B");
    }

    return 0;
}
