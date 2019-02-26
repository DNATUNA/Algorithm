#include<stdio.h>
int main()
{
	int score[5] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] < 40) score[i] = 40;
		if (i >= 1) score[0] += score[i];
	}

	printf("%d", score[0] / 5);
}