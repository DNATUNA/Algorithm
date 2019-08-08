#include<cstdio>

int num;
int ans[5];
int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a == 0 || b == 0) ans[4]++;
		else if (b > 0) {
			if (a > 0) ans[0]++;
			else ans[1]++;
		}
		else {
			if (a > 0)ans[3]++;
			else ans[2]++;
		}
	}
	
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", ans[0], ans[1], ans[2], ans[3], ans[4]);
}