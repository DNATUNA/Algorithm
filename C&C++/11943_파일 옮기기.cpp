#include<cstdio>

int main() {
	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if ((a + d) > (b + c))
		printf("%d", b + c);
	else
		printf("%d", a + d);
}