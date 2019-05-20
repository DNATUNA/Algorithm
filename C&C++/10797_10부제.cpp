#include<cstdio>

int main() {
	int num = 0, tmp = 0, count = 0;
	scanf("%d", &num);
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &tmp);
		if (tmp == num) count++;
	}
	printf("%d", count);
}