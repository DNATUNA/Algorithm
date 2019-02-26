#include<stdio.h>

int main() {
	int a[2]{ 0, }, num = 0, s_n=0, b_1=0, c_1=0, b_2=0, c_2=0, cy=0;

	scanf("%d", &num);
	s_n = num;

	while (1) {
		b_1 = num / 10;
		c_1 = num % 10;

		num = b_1 + c_1;

		b_2 = num / 10;
		c_2 = num % 10;

		cy++;

		num = c_1 * 10 + c_2;
		if (s_n == num) break;

	}
	printf("%d", cy);
}