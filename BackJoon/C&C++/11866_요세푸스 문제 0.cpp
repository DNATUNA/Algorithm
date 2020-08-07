#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	queue<int> num;

	for (int i = 0; i < n; ++i) {
		num.push(i + 1);
	}

	vector<int> ans(n);

	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < k - 1; ++a) {
			num.push(num.front());
			num.pop();
		}
		ans[i] = num.front();
		num.pop();
	}

	printf("<");
	for (int i = 0; i < n; ++i) {
		printf("%d", ans[i]);
		if (i == n - 1) printf(">");
		else printf(", ");
	}
}
