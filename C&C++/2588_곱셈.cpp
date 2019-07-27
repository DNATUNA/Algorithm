#include<cstdio>

int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int ans = a * b;

	printf("%d\n", a * (b % 10));
	b /= 10;
	printf("%d\n", a * (b % 10));
	b /= 10;
	printf("%d\n", a * (b % 10));
	printf("%d", ans);
}