#include<stdio.h>
int main()
{
	double a, b;
	scanf("%lf%lf", &a, &b);

	printf("%0.22g", a/b);
}