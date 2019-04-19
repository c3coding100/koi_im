#include <stdio.h>
int GCD(int a,int b)
{
    if(a<b) return GCD(b,a);
    if(b==0) return a;
    return GCD(b, a%b);
}
int LCM(int a, int b) // 최소공배수
{
    return a / GCD(a, b)*b;
}

int main(void)
{
    int gcd, lcm;
    scanf("%d%d", &gcd, &lcm);
    int div = lcm / gcd;    // lcm/gcd = A * B

    int A, B, j;
    for (int i = 1; ; ++i)
    {
        if (div % i != 0)
            continue;       // 정수 아닌 값 제외
        j = div / i;
        if (LCM(i * gcd, j * gcd) != lcm)
            continue;
        if (i > j)
            break;         // i, j 값이 역전 된 경우 최소
        A = i;
        B = j;
    }
    printf("%d %d\n", A * gcd, B * gcd);

    return 0;
}
