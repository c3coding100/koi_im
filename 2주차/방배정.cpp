#include <stdio.h>
int n, k;
int cnt[7][2];
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int gender, year;
		scanf("%d %d", &gender, &year);
		cnt[year][gender]++;
	}

	int ans = 0;

	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j <= 1; j++) ans += (cnt[i][j] + k - 1) / k;
	}
	printf("%d\n", ans);
	return 0;
}
