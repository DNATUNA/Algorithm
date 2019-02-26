#include<stdio.h>

void check(int a) {
	int b = 0;
	while (a>0) {
		b = b + (a % 10)*(a % 10);
		a /= 10;
	}
	if (b == 1) printf("HAPPY");
	else if (b == 85 || b == 58) printf("UNHAPPY");
	else check(b);
}
int main() {
	int a = 0;
	scanf("%d", &a);

	check(a);
}