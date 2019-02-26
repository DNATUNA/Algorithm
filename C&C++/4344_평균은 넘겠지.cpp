#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int n = 0, num = 0, sum = 0, stack = 0;
	float ans = 0.00000f;
	scanf("%d", &n);


	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		vector<int> a(num);

		for (int j = 0; j < num; ++j) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		sum /= num;
		for (int k = 0; k < num; ++k) if (a[k] > sum) ++stack;

		ans = (float)stack / num;

		printf("%.3f%%\n", ans * 100);
		sum = 0; stack = 0;
	}
}
