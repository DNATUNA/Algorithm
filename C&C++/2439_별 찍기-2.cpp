#include<stdio.h>
int main() {
	int A = 0;
	scanf("%d", &A);
	int B = 1;

	for (int i = 0; i < A; ++i) {
		for (int j = A - B; j > 0; --j) {
			printf(" ");
		}
		for (int k = 0; k < B; ++k) {
			printf("*");
		}
		printf("\n");
		++B;
	}
}