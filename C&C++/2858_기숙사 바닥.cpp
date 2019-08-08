#include<cstdio>

int main() {
	int a, b;

	scanf("%d%d", &a, &b);

	int size = a + b, len = (a + 4) / 2;

	for (int i = 1; i <= len / 2; ++i) {
		if (i * (len - i) == size) {
			printf("%d %d", len - i, i);
			break;
		}
	}
}