#include<cstdio>

int main() {
	int n = 0;
	int a = 0, b = 0, gcd = 1, lcm = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);

		for (int i = 2; i; ++i) {
			if ((a % i == 0) && (b % i == 0)) {
				a /= i, b /= i;
				gcd *= i;
				i = 1;
			}
			else if ((a < i) || (b < i)) {
				lcm = gcd * a * b;
				break;
			}
		}
		printf("%d %d\n", lcm, gcd);
		lcm = 1, gcd = 1;
	}
}