#include<stdio.h>

int MIN(int a, int b);

int main()
{
	int n = 0, money[1001][3] = { 0, }, d[1001][3] = {0,};
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &money[i][j]);

	for (int i = 1; i <= n; ++i) {
		d[i][0] = MIN(d[i - 1][1], d[i - 1][2]) + money[i][0];
		d[i][1] = MIN(d[i - 1][0], d[i - 1][2]) + money[i][1];
		d[i][2] = MIN(d[i - 1][0], d[i - 1][1]) + money[i][2];
	}
	
	printf("%d", MIN(MIN(d[n][0], d[n][1]),d[n][2]));
}
int MIN(int a, int b) {
	return a < b ? a : b;
}