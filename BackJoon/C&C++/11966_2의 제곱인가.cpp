#include<cstdio>

int main() {
	int n = 0;
	scanf("%d", &n);

	while (n != 1) {
		if (n % 2 == 1) {
			printf("0");
			break;
		}
		n /= 2;
	}
	if (n == 1)printf("1");
}