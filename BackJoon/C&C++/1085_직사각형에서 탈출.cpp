#include<cstdio>
int main() {
	int x = 0, y = 0, w = 0, h = 0;
	
	scanf("%d%d%d%d", &x, &y, &w, &h);

	int check1 = w-x, check2 = h-y;
	int min1 = x < y ? x : y, min2 = check1 < check2 ? check1 : check2;

	printf("%d", min1 < min2 ? min1 : min2);
}
