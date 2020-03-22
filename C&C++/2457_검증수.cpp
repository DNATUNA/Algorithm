#include<cstdio>

int main() {
	int num[5] = { 0, };
	for (int i = 0; i < 5; ++i)
		scanf("%d", &num[i]);

	int ans = 0;
	for (int i = 0; i < 5; ++i)
		ans = ans + (num[i] * num[i]);

	printf("%d", ans % 10);
}