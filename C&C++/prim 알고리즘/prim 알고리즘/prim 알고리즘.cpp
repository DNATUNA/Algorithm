#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int quiz[SIZE][SIZE] = { 0, };
int selected[SIZE] = { 0, };
int dist[SIZE] = { 0, };

int Min() {
	int index = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!selected[i]) {
			index = i;
			break;
		}
	}

	for (int i = 0; i < SIZE; i++)
		if (!selected[i] && ((dist[i] < dist[index]) || ((dist[index] == 0) && (dist[i] != 0))))
			index = i;

	return index;
}
void main()
{
	FILE *fp;
	char buffer[100 * SIZE];
	char *ptr;

	int cost_sum = 0;

	fp = fopen("quiz.csv", "r");

	if (fp == NULL) {
		puts("file open failed!!");

		return;
	}

	for (int i = 0; i < SIZE; i++) {
		fgets(buffer, 100 * SIZE, fp);
		ptr = strtok(buffer, ",");
		int j = 0;

		while (ptr != NULL) {
			quiz[i][j] = atoi(ptr);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);

	int min_dist = 1000L, stack = 0, a = 0, b = 0;


	while (stack != SIZE) {

		a = Min();
		selected[a] = 1;

		for (int i = 0; i < SIZE; i++) {
			if (quiz[a][i] != 0)
				if (!selected[i] && ((quiz[a][i] < dist[i] || dist[i] == 0)))
					dist[i] = quiz[a][i];
		}
		if (stack > 0)
			printf("%d to %d, cost : %d\n", b, a, dist[a]);

		cost_sum += dist[a];
		b = a;
		stack++;
	}

	printf("total cost : %d", cost_sum);

}