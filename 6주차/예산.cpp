#include <cstdio>
#include <algorithm>
#define MAXN 10000
using namespace std;
int N, M;
int A[MAXN];
int main(void)
{
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);

    sort(A, A + N);

    int sum = 0, ans = 0;
    for (i = 0; i < N; i++) {
        if (sum + A[i] * (N - i) > M) {
            ans = (M - sum) / (N - i);
            break;
        } else {
            sum += A[i];
        }
    }
    if (i == N) {
        ans = A[N - 1];
    }

    printf("%d\n", ans);

    return 0;
}
