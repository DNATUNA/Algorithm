#include<stdio.h>
int main() {
	int num[1000] = { 0, }, n = 0, chk = 0, max = 0;

	scanf("%d", &n);
	scanf("%d", &num[0]);

	if (n == 1) printf("0");
	for (int i = 1; i < n; ++i) {
		scanf("%d", &num[i]);
		if (num[i] > num[i - 1]) {
			chk += num[i] - num[i - 1];
			max = chk > max ? chk : max;
		}
		else chk = 0;
	}

	printf("%d", max);
}