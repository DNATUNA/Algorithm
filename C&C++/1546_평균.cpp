#include<stdio.h>
int main()
{
	int n, a[1000] = { 0, }, save;
	float sum=0.0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int j = 0; j < (n - 1); j++)
	{
		if (a[j] > a[j + 1])
		{
			save = a[j];
			a[j] = a[j + 1];
			a[j + 1] = save;
		}
	}
	float b = (float)a[n - 1];
	float s_a[1000] = { 0. };
	for (int k = 0; k < n; k++)
	{
		s_a[k] = (((float)a[k] / b) * 100.0);
	}

	for (int l = 0; l < n; l++)
	{
		sum += s_a[l];
	}
	printf("%0.2f", sum / (float)n);
}