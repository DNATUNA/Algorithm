#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);

	int three, five;

	five = n / 5;
	n %= 5;

	while (five >= 0)
	{
		if ((n % 3)==0)
		{
			three = n / 3;
			printf("%d", five + three);
			return 0;
		}

		five--;
		n += 5;
	}

	printf("-1");
}