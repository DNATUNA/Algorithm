#include<stdio.h>

int a[13] = { 1, 1, 2, 6, 24, 120, 720 };
int fac(int n);

int main() {
	int n = 0;
	scanf("%d", &n);

	fac(n);
	printf("%d", a[n]);
}

int fac(int n) {
	if (a[n] != 0)
		return a[n];
	else {
		a[n] = fac(n - 1)*n;
		return a[n];
	}
}