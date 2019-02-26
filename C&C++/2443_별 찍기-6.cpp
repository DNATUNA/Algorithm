#include<stdio.h>
int main(){
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i){
		for (int j = i; j>0; --j) printf(" ");
		for (int k = (n - i -1)*2+1; k > 0; --k) printf("*");
		
		printf("\n");
	}
}