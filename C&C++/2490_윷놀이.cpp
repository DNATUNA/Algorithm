#include<stdio.h>

int main() {
	int n = 0, count = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &n);
			if (n == 1) count++;
		}
		if (count == 0)printf("D\n");
		else if (count == 1)printf("C\n");
		else if (count == 2)printf("B\n");
		else if (count == 3)printf("A\n");
		else if (count == 4)printf("E\n");

		count = 0;
	}
}