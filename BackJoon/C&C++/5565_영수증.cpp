#include<cstdio>

int main() {
	int total = 0, see = 0, tmp = 0;
	scanf("%d", &total);

	for (int i = 0; i < 9; ++i) {
		scanf("%d", &tmp);
		see += tmp;
	}
	printf("%d", total - see);
}