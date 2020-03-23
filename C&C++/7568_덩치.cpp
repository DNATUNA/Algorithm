#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> list(n);

	for (int i = 0; i < n; ++i)
		scanf("%d%d", &list[i].first, &list[i].second);

	vector<int> ans(n, 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if ((list[i].first < list[j].first) && (list[i].second < list[j].second))
				ans[i]++;
		}
	}

	for (auto i : ans)
		printf("%d ", i);
}