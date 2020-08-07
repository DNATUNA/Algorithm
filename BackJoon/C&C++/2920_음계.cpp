#include<stdio.h>
int main()
{
	int check[8] = { 0, }, find=0;
	for (int i = 0; i < 8; i++)scanf("%d", &check[i]);

	if (check[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if ((i+1) == check[i])find++;
		}
		if (find == 7) printf("ascending");
		else printf("mixed");
	}
	else if (check[0] == 8)
	{
		for (int j = 1; j < 8; j++)
		{
			if ((j+1) == (9- check[j]))find++;
		}
		if (find == 7) printf("descending");
		else printf("mixed");
	}
	else printf("mixed");
}