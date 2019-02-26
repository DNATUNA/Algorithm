#include<stdio.h>

int gcd(int a, int b);

int main() {
	int a = 0, b = 0, c;
	scanf("%d%d", &a, &b);
	c=gcd(a, b);
	printf("%d", a*b / c);
}

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d\n", a);
    return a;
}