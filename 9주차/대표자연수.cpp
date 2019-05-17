#include<stdio.h>
#include<algorithm>
using namespace std;

int a[20001];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    int m = (n-1)/2;
    printf("%d", a[m]);
}
