#include<stdio.h>
int main() {
	int a=0, b[2] = { 1, 0 }, tmp=0;
	scanf("%d", &a);
	if (a == 1) printf("%d", 1);
	else {
		for (int i = 0; i < a; ++i) {
			tmp = b[0] + b[1];
			b[0] = b[1];
			b[1] = tmp;
		}
		printf("%d", tmp);
	}
}