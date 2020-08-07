#include<stdio.h>
#include<string.h>
int main() {
	char txt[101] = "";
	scanf("%s", txt);

	int len = strlen(txt);

	for (int i = 1; i <= len; ++i) {
		printf("%c", txt[i-1]);
		if (i % 10 == 0) printf("\n");
	}
}