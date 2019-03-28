#include<stdio.h>
int n;
long long int f[100];
int main() {
	int i;
	scanf("%d", &n);
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i <= n+2; i++) {
		f[i] = f[i-2] + f[i-1];
	}
	printf("%lld\n", f[n+2]*2);
	return 0;
}
