#include<stdio.h>
int main() {
	int num = 0;
	scanf("%d", &num);
	if (num > 89)printf("A");
	else if (num < 90 && num>79)printf("B");
	else if (num < 80 && num>69)printf("C");
	else if (num < 70 && num>59)printf("D");
	else printf("F");
}
