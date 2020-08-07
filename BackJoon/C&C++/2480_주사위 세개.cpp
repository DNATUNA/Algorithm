#include<cstdio>

int main() {
	int a = 0, b = 0, c = 0;
	int tmp = 0, count = 1;

	scanf("%d%d%d", &a, &b, &c);

	if (a == b) {
		tmp = a;
		count++;
		if (a == c) count++;
	}
	else if (a == c) {
		tmp = a;
		count++;
	}
	else if (b == c) {
		tmp = b;
		count++;
	}

	if (count == 3)
		printf("%d", 10000 + (tmp * 1000));
	else if (count == 2)
		printf("%d", 1000 + (tmp * 100));
	else {
		int max = 0;
		if (a > max)max = a;
		if (b > max)max = b;
		if (c > max) max = c;

		printf("%d", max * 100);
	}

}