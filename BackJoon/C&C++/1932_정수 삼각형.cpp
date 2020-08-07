#include<stdio.#include<stdio.h>

int MAX(int a, int b);

int main() {
	int n = 0, tmp = 0;
	int d[501][501] = { 0, }, num[501][501] = { 0, };
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
			scanf("%d", &num[j][i]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j != 0 && j != i - 1) {
				d[j][i] = MAX(d[j - 1][i - 1], d[j][i - 1]) + num[j][i];
				tmp = MAX(tmp, d[j][i]);
			}
			else if (j == 0) {
				d[j][i] = d[j][i - 1] + num[j][i];
				tmp = MAX(tmp, d[j][i]);
			}
			else {
				d[j][i] = d[j - 1][i - 1] + num[j][i];
				tmp = MAX(tmp, d[j][i]);
			}
		}
	}
	printf("%d", tmp);
}

int MAX(int a, int b) {
	return a >= b ? a : b;
}h>
#include<iostream>

using namespace std;

int main() {
	int a = 0, b = 0, count = 0;
	scanf("%d%d", &a, &b);

	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < a-1; ++i) {
		count += day[i];
	}

	switch ((count+b) % 7) {
	case 0: {
		printf("SUN");
		break;
	}
	case 1: {
		printf("MON");
		break;
	}
	case 2: {
		printf("TUE");
		break;
	}
	case 3: {
		printf("WED");
		break;
	}
	case 4: {
		printf("THU");
		break;
	}
	case 5: {
		printf("FRI");
		break;
	}
	case 6: {
		printf("SAT");
		break;
	}
	}
}
