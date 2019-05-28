#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n = 0, m = 0;

	scanf("%d%d", &n, &m);
	vector<int> num(m + 1, 1);

	int check = 1;

	num[0] = 0, num[1] = 0;
	while (1) {
		if (check >= m) break;
		while(++check<=m) {
			if (num[check] == 1) break;
		}
		for (int a = 2; check * a <= m; ++a)
			num[check * a] = 0;
	}
	for (int a = n; a <= m; ++a) {
		if (num[a] == 1)printf("%d\n", a);
	}
}