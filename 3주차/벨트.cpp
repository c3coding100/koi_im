#include <stdio.h>
int main()
{
    int i, j;
    int n;
    int a, b, s;
    int dir = 0;
    int speed = 1;

    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf( "%d %d %d", &a, &b, &s);
        if(s == 1)
            dir = 1 - dir;
        speed = speed * b/a;

    }
    printf("%d %d", dir, speed);
    return 0;
}
