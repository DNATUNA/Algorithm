#include<cstdio>

int sum(int i, int n) {
	int tmp = i;
	for (i; i != 0; i /= 10)
		tmp += i % 10;
	if (tmp == n) return 1;
	else return 0;

}
int main() {
	int n = 0;

	scanf("%d", &n);

	int i = 1;
	while (1) {
		if (sum(i, n) == 1) {
			printf("%d", i);
			break;
		}
		else if (i++ > n) {
			printf("0");
			break;
		}
	}
}