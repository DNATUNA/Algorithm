#include<stdio.h>
int main() {
	int A = 0;
	scanf("%d", &A);
	int B = 0;

	for (int i = 0; i < A; ++i) {
		for (int k = 0; k < B; ++k) {
			printf(" ");
		}
		for (int j = A - B; j > 0; --j) {
			printf("*");
		}
		printf("\n");
		++B;
	}
}