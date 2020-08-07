#include<cstdio>

int main() {
	int a, ans = 0;
	
	scanf("%d", &a);

	a = 1000 - a;
	while (a != 0) {
		if (a >= 500) {
			a -= 500;
			ans++;
		}
		else if (a >= 100) {
			a -= 100;
			ans++;
		}
		else if (a >= 50) {
			a -= 50;
			ans++;
		}
		else if (a >= 10) {
			a -= 10;
			ans++;
		}
		else if (a >= 5) {
			a -= 5;
			ans++;
		}
		else {
			a -= 1;
			ans++;
		}
	}

	printf("%d", ans);
}