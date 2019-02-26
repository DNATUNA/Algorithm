#include<stdio.h>
int main() {
	int A = 0;
	scanf("%d", &A);

	for (int i = A; i > 0; --i) {
		printf("%d\n", i);
	}
}