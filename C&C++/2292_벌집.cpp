#include<cstdio>

int main() {
	int num = 0;
	scanf("%d", &num);
	
	int ans = 0, check = 1;
	while (1) {
		check = check + ( ans * 6 );
		if (check >= num)
			break;
		else ans++;
	}
	printf("%d", ans + 1);
}