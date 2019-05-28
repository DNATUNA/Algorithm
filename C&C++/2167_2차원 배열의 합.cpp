#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n = 0, m = 0, tmp = 0;

	scanf("%d%d", &n, &m);

	vector<vector<int>> num(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &num[i][j]);
		
	int k = 0;

	scanf("%d", &k);
	
	for (int n = 0; n < k; ++n) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0, ans = 0;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);

		for (int x = x1; x <= x2; ++x)
			for (int y = y1; y <= y2; ++y)
				ans += num[y - 1][x - 1];				

		printf("%d\n", ans);
	}

}