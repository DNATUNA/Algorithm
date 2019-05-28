#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n = 0, m = 0;

	scanf("%d%d", &n, &m);
	vector<int> num(n + 1, 1);

	int check = 1, stack = 0, ans = 0;

	while (ans == 0) {
		while(++check<=n) {
			if (num[check] == 1) break;
		}
		for (int a = 1; check * a <= n; ++a) {
			if (num[check * a] != 0) {
				num[check * a] = 0;
				stack++;
			}
			if (stack == m) {
				ans = check * a;
				break;
			}
		}
	}
	printf("%d", ans);
}