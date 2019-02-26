#include<stdio.h>

long long int fibo(int n);
long long int a[90] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
int main()
{
	int n = 0;
	scanf("%d", &n);

	fibo(n-1);

	printf("%lld", a[n - 1]);
}

long long int fibo(int n) {
	if (n <= 1)
		return 1;
	else if (a[n] != 0)
		return a[n];
	else {
		a[n] = fibo(n - 1) + fibo(n - 2);
		return a[n];
	}
}