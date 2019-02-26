#include<stdio.h>
int main()
{
	int a, b, c, num, check; scanf("%d%d%d", &a, &b, &c);
	int count[10] = { 0, };

	num = a*(b*c);

	while (num != 0)
	{
		check = num % 10;
		for (int i = 0; i < 10; i++)
		{
			if (check == i)
			{
				count[i]++;
				break;
			}
		}
		num /= 10;
	}
	for (int j = 0; j < 10; j++) printf("%d\n", count[j]);
}