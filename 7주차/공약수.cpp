#include <stdio.h>
int GCD(int a,int b)
{
    if(a<b) return GCD(b,a);
    if(b==0) return a;
    return GCD(b, a%b);
}
int LCM(int a, int b) // �ּҰ����
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
            continue;       // ���� �ƴ� �� ����
        j = div / i;
        if (LCM(i * gcd, j * gcd) != lcm)
            continue;
        if (i > j)
            break;         // i, j ���� ���� �� ��� �ּ�
        A = i;
        B = j;
    }
    printf("%d %d\n", A * gcd, B * gcd);

    return 0;
}
