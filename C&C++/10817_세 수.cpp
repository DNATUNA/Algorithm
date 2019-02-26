#include<stdio.h>
int main()
{
	int a[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	int save;
	for (int k = 1; k < 3; k++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[j] >= a[j + 1])
			{
				save = a[j];
				a[j] = a[j + 1];
				a[j + 1] = save;
			}
		}
	}
	
	printf("%d", a[1]);
}