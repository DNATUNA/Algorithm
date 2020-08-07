#include<stdio.h>
int main() {
	long long int A = 0LL, B=0LL, C=0LL;
	scanf("%lld%lld%lld", &A, &B, &C);
	
	long long int ans=1LL;
	while (B) {
		if (B % 2 == 1) {
			ans *= A;
			ans %= C;
		}
		A *= A;
		A %= C;
		B /= 2;
	}

	printf("%lld", ans);
}