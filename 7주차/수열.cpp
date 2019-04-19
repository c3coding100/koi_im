#include <cstdio>
int n,k;
int data[100005];
int main(void)
{
    int i;

    scanf("%d%d", &n, &k);
    if(k == 0)
        return 0;

    int sum = 0;
    int max_sum = -99999999;

    for(i=0;i<n;i++)
    {
        scanf("%d", &data[i]);
        if(data[i] > 100 || data[i] < -100)
            return -1;
        sum += data[i];
        if(i >= k-1)
        {
            if(sum > max_sum)
                max_sum = sum;
            sum -= data[i-k+1];
        }
    }
    printf("%d\n", max_sum);
    return 0;
}
