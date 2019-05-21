#include<cstdio>

int main() {
	int a = 0, b = 0, c = 0, sum = 0;
	scanf("%d%d%d", &a, &b, &c);

	for (int i = 0; i < a; ++i) {
		sum += b * (i + 1) + c * (i + 1) * (i + 1);
	}
	printf("%d", sum);
}