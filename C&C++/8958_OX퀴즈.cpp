#include<stdio.h>
#include<string.h>
int main() {
	char test[81] = "";
	int n = 0, len=0, score=0, stack=0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", test);
		len = strlen(test);
		for (int j = 0; j < len; ++j) {
			if (test[j] == 'O')	score += ++stack;
			else stack = 0;
		}
		printf("%d\n", score);
		score = 0; stack = 0;
	}
}