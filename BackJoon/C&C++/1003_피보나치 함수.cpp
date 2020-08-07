#include<stdio.h>

int fibonacci(int n, int i);

int t[41][2] = { { 1, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 },{ 2, 3 },{ 3, 5 },{ 5, 8 },{ 8, 13 },{ 13, 21 },{ 21, 34 },{ 34, 55 } };

int main() {
	int  num = 0, a = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &a);

		t[a][0] = fibonacci(a, 0);
		t[a][1] = fibonacci(a, 1);
		printf("%d %d\n", t[a][0], t[a][1]);
	}
}

int fibonacci(int n, int i)
{
	if (n <= 1)
		return t[n][i];
	if (t[n][i] != 0) 
		return t[n][i];
	t[n][i] = fibonacci(n - 1, i) + fibonacci(n - 2, i);
	return t[n][i];
}
