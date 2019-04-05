#include <cstdio>
void convert(int num, int base) {
    if (num == 0) return;
    convert(num/base, base);
    printf("%d ",num%base);
}

int main() {
    int a,b;
    scanf("%d%d", &a, &b);
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        ans = ans * a + x;
    }
    convert(ans,b);
    return 0;
}
