#include<cstdio>

int main() {
	; int n = 0, num = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		for (int j = 0; j < num; ++j)printf("=");
		printf("\n");
	}
}