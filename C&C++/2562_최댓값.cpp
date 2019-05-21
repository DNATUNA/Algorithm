#include<cstdio>

int main() {
	int count = 0, max = 0, tmp = 0;

	for (int i = 1; i < 10; ++i) {
		scanf("%d", &tmp);
		if (max < tmp) {
			max = tmp;
			count = i;
		}
	}
	printf("%d\n%d", max, count);
}