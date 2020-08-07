#include<cstdio>

int main() {
	int n = 0, tmp = 0, min = 2000000, max = -2000000;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (tmp < min) min = tmp;
		if (tmp > max)max = tmp;
	}
	printf("%d %d", min, max);
}