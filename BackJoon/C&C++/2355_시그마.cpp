#include<stdio.h>

int main() {
	long long int A = 0, B = 0, tmp;
	scanf("%lld%lld", &A, &B);

	if (A < B) {
		tmp = A;
		A = B;
		B = tmp;
	}
	tmp = A - B + 1;

	if (tmp % 2 == 0) printf("%lld", (A + B)*tmp / 2);
	else printf("%lld", ((A + B)*(tmp - 1) / 2 + (A + B) / 2));
}