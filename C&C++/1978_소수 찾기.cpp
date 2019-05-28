#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n = 0, m = 0, ans = 0;

	scanf("%d", &n);
	vector<int> num1(n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		num1[i] = m;
	}

	int check = 1;
	sort(num1.begin(), num1.end());
	m = num1[num1.size() - 1];
	vector<int> num(m+1, 1);

	num[0] = 0, num[1] = 0;
	while (1) {
		if (check >= m) break;
		while (++check <= m) {
			if (num[check] == 1) break;
		}
		for (int a = 2; check * a <= m; ++a)
			num[check * a] = 0;
	}
	for (int a = 0; a < n; ++a)
		if (num[num1[a]] == 1) ans++;
	
	printf("%d", ans);
}