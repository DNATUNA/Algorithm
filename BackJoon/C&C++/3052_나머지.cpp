#include<stdio.h>
int main() {
	int num[42] = { 0, }, n=0, stack=0;

	for (int i = 0; i < 10; ++i) {
		scanf("%d", &n);
		num[n % 42]++;
	}

	for (int i = 0; i < 42; ++i) 
		if (num[i] > 0) stack++;
	
	printf("%d", stack);
}