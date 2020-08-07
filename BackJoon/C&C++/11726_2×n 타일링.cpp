#include<stdio.h>

int a[1001] = { 1, 2, 3, 5, 8, 13 };

int fib(int n);

int main(){
	int n = 0;
	scanf("%d", &n);
	
	fib(n - 1);

	printf("%d", a[n - 1]);
}

int fib(int n){
	
	if (a[n] != 0)
		return a[n];

	else
		a[n] = fib(n - 1) + fib(n - 2);
	if (a[n] > 10007) a[n] %= 10007;
		return a[n];
}