#include<stdio.h>
int main()
{
	char str[101][101] = { 0, };
	int i=0;
	while (i<100)
	{
		gets(str[i]);
		puts(str[i]);
		i++;
	}
}