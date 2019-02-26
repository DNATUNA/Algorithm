#include<stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);

	if (num < 111) {
		if (num < 99) printf("%d", num);
		else printf("99");
	}
	else {
		int stack = 111, a = 0, b = 0, c = 0, check = 99;
		while (stack <= num) {
			a = stack / 100;
			b = stack / 10; b %= 10;
			c = stack % 10;

			if ((b - a) == (c - b))check++;
			stack++;
		}
		printf("%d", check);
	}
}
