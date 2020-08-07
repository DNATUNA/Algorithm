#include<stdio.h>
#include<string.h>
int main() {
	char txt[101] = "";
	scanf("%s", txt);

	int len = strlen(txt), j=0;

	for (int i = 0; i < 26; ++i) {
		for (j = 0; j < len; ++j) {
			if (i + 'a' == txt[j]) {
				printf("%d", j);
				break;
			}
		}
		if (j == len) printf("-1");
		printf(" ");
	}
}