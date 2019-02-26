#include<stdio.h>

int a[1000] = { 1, 2, 1, 1, 1, 1, 2, 1, 2, 1};

int check(int n);
int main() {
	int n = 0;
	scanf("%d", &n);

	check(n-1);
	if (a[n - 1] == 1)printf("SK");
	else if(a[n-1] == 2) printf("CY");
}

int check(int n) {
	if (a[n] != 0)
		return a[n];
	else {
		a[n] = 1;
		if (check(n - 1) == 1&& check(n - 3) == 1&& check(n - 4) == 1) a[n] = 2;
		return a[n];
	}
}