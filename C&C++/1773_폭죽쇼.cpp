#include<stdio.h>
int main() {
	int n = 0, c = 0, stack=0, count=0;
	int num[100] = { 0, };

	scanf("%d%d", &n, &c);

	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i]);

	for (int i = 1; i <= c; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i%num[j] == 0)stack++;
		}
		if (stack > 0) count++;

		stack = 0;
	}
	printf("%d", count);
}