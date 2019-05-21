#include<cstdio>

int main() {
	int n = 0, tmp = 0, yes = 0, no= 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (tmp == 1)yes++;
		else no++;
	}
	if (yes > no)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
}