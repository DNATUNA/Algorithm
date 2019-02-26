#include<stdio.h>
int main() {
	int num = 0;
	scanf("%d", &num);
	int a = 0, b = 0;
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
}