#include<cstdio>

int main() {
	int T = 0, k = 0, n = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int mem[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
		scanf("%d%d", &k, &n);
		for (int a = 0; a < k; ++a) {
			for (int b = 0; b < n; ++b) {
				if (b == 0) continue;
				else mem[b] = mem[b] + mem[b - 1];
			}
		}
		printf("%d\n", mem[n - 1]);
	}
}