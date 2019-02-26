#include<stdio.h>
int main() {
	int n = 0, x = 0, c=0;
	scanf("%d%d", &n, &x);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &c);
		if (c < x) printf("%d ", c);
	}
}
