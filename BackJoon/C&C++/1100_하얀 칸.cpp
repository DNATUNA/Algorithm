#include<stdio.h>
int main()
{
	char board[9][9] = {"", };
	int count = 0;


	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			scanf("%c", &board[i][j]);
			if (board[i][j] == '\n') {
				j--;
				continue;
			}
			if (j % 2 == 0 && i % 2 == 0 && board[i][j] == 'F') count++;
			if (j % 2 == 1 && i % 2 == 1 && board[i][j] == 'F') count++;
		}
	}

	printf("%d", count);
}
