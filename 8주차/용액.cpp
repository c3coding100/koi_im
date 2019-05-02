#include <stdio.h>
int main(void)
{
    int N, arr[100010], result[2];

    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }

    int min = 1234567890;
    int sum;
    int plussum;
    int left=1;
    int right = N;

    while(left <right) {
        sum = arr[left] + arr[right];
        plussum = sum;
        if(plussum<0) plussum*=-1;
        if(min > plussum) {
            min = plussum;
            result[0] = arr[left];
            result[1] = arr[right];
        }
        if(sum<0) left++;
        else right--;
    }
    printf("%d %d\n", result[0], result[1]);
    return 0;
}
