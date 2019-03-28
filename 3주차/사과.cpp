#include <stdio.h>
int main()
{
    int i;
    int n;
    int apple, people;
    int sum = 0;

    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d %d", &people,&apple);
        sum = sum + (apple % people);
    }
    printf("%d",sum);

    return 0;
}
