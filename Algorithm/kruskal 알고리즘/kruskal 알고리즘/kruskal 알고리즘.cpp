/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000
#define DOT_NUM 100

void input_quiz(int(*quiz)[3], const char *fileDir);

void main()
{
	char *fileDir = (char *)"./quiz_4.csv";
	int quiz[SIZE][3];
	int weight_sum = 0;

	// write your var

	input_quiz(quiz, fileDir);

	// write bubble sorting code
	int stack = SIZE - 1, tmp = 0;

	while (stack != 0) {
		for (int i = 0; i < stack; ++i)
			if (quiz[i][2] > quiz[i + 1][2]) {
				for (int j = 0; j < 3; ++j) {
					tmp = quiz[i + 1][j];
					quiz[i + 1][j] = quiz[i][j];
					quiz[i][j] = tmp;
				}
			}
		stack--;
	}

	// print 6712th weight
	printf("6712th dot's weight : %d\n", quiz[6711][2]);

	// write kruskal MST code
	int selected[DOT_NUM][DOT_NUM] = { 0, }, dotSel[DOT_NUM] = { 0, }, count = 0, i = 0, line = 0;

	while (count != DOT_NUM) {
		if ((selected[quiz[i][0]][quiz[i][1]] == 1 && selected[quiz[i][1]][quiz[i][0]] == 1) ||
			(dotSel[quiz[i][0]] != 0 && dotSel[quiz[i][1]] != 0 && dotSel[quiz[i][0]] == dotSel[quiz[i][1]])) {
			i++;
		}
		else {
			if (dotSel[quiz[i][0]] == 0 && dotSel[quiz[i][1]] == 0)
				count += 2, line++, dotSel[quiz[i][0]] = line, dotSel[quiz[i][1]] = line;
			else if (dotSel[quiz[i][0]] == 0 && dotSel[quiz[i][1]] != 0)
				count++, dotSel[quiz[i][0]] = dotSel[quiz[i][1]];
			else if (dotSel[quiz[i][0]] != 0 && dotSel[quiz[i][1]] == 0)
				count++, dotSel[quiz[i][1]] = dotSel[quiz[i][0]];
			else
				for (int j = 0; j < DOT_NUM; ++j)
					if (dotSel[j] == dotSel[quiz[i][0]]) dotSel[j] = dotSel[quiz[i][1]];
			weight_sum += quiz[i][2], selected[quiz[i][0]][quiz[i][1]] = 1, selected[quiz[i][1]][quiz[i][0]] = 1, i++;
		}
	}

	printf("%d th ", i);
	printf("cost_sum = %d\t \n", weight_sum);

}

void input_quiz(int(*quiz)[3], const char *fileDir)
{
	FILE *fp;
	char buffer[SIZE * 3];
	char *ptr;
	int i = 0, j = 0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("quiz file open failed!!");

		return;
	}

	for (i = 0; i < SIZE; i++)
	{
		fgets(buffer, SIZE * 3, fp);
		ptr = strtok(buffer, ",");
		j = 0;

		while (ptr != NULL)
		{
			quiz[i][j] = atof(ptr);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);
}*/