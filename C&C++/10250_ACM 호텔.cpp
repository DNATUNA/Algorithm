#include<stdio.h>
int main()
{
	int test, H, W, N;

	scanf("%d", &test);
	int ans[100], count = 1;
	for (int i = 1; i <= test; i++)
	{
		scanf("%d%d%d", &H, &W, &N);
		while (1)
		{
			if (N > H)
			{
				N = N - H;
				count++;
			}
			else break;
		}
		N = N * 100;
		ans[i] = N + count;
		count = 1;
	}
	for (int j = 1; j <= test; j++)
	{
		printf("%d\n", ans[j]);
	}
}