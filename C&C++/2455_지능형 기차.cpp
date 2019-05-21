#include<cstdio>

int main() {
	int a[2] = { 0, }, b[2] = { 0, }, c[2] = { 0, }, d[2] = { 0, };
	int tmp=0, max = 0;

	scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1], &d[0], &d[1]);

	tmp += a[1];
	if (max < tmp) max = tmp;
	tmp = tmp - b[0] + b[1];
	if (max < tmp) max = tmp;
	tmp = tmp - c[0] + c[1];
	if (max < tmp) max = tmp;
	tmp = tmp - d[0] + d[1];
	if (max < tmp) max = tmp;

	printf("%d", max);
}