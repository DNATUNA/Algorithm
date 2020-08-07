#include<stdio.h>

int main() {
	int num = 0, sum=0;
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i) sum += i;
	printf("%d", sum);
}