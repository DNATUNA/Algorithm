#include<cstdio>
#include<string.h>
int main() {
	char st[51];
	int n = 0, check = 0;

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; ++i) {
		scanf("%[^\n]", st);
		getchar();
		
		for (int j = 0; j < strlen(st) / 2; ++j) {
			if (st[i] > 47 && st[i] < 58) {
				if (st[j] != st[strlen(st) - j - 1]) {
					check++;
					break;
				}
			}
			else {
				if ((st[j] != st[strlen(st) - j - 1]) && (st[strlen(st) - j - 1] - st[j] != 32) && (st[j] - st[strlen(st) - j - 1] != 32)) {
					printf("%c %c %d",st[j],st[strlen(st)-j-1], st[strlen(st) - j - 1] - st[j]);
					check++;
					break;
				}
			}
			
		}
		if (check == 0) printf("Yes\n");
		else printf("No\n");
		
		check = 0;
	}
}