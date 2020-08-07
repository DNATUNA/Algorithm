#include<cstdio>

int main() {
	long long int n = 0, stack = 0;
	scanf("%lld", &n);
	for (long long int i = 1; i; ++i) {
		n -= i;
		stack++;
		if (n <= i) break;
	}
	printf("%lld", stack);
}