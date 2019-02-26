#include<stdio.h>
int main(){
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i){
		for (int j = n - i; j>1; --j) printf(" ");
		for (int k = 0; k < i*2+1; ++k) printf("*");
		printf("\n");
	}
}