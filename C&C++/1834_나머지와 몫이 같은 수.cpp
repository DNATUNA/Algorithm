#include<cstdio>

int main() {
	long long int n = 0, stack = 0;
	scanf("%lld", &n);

	for (long long int i = 0; i < n; ++i)
		stack += n * i + i;

	printf("%lld", stack);
}