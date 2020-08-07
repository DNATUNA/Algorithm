#include<stdio.h>

int a[11] = { 1, 2, 4, 7, 13 };

int sol(int n);
int main(){
	int n = 0, ca=0;
	scanf("%d", &ca);
	for (int i = 0; i < ca; ++i){
		scanf("%d", &n);

		sol(n - 1);

		printf("%d\n", a[n - 1]);
	}
}

int sol(int n){
	
	int ans = 0;

	if (a[n] != 0)
		return a[n];

	else
		a[n] = sol(n - 1) + sol(n - 2) + sol(n - 3);
		return a[n];
}