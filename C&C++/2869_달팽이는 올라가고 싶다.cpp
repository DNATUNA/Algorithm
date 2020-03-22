#include<cstdio>

int main() {
	int A, B, V;

	scanf("%d%d%d", &A, &B, &V);

	int ans = 0, tmp = A;
	
	ans = (V - A) / (A - B);
	if ((V - A) % (A - B)) ++ans;

	printf("%d", ++ans);
}