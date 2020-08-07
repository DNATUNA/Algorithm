#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int ans = 0, sum = 0;

	vector<int> a(9);

	for (int i = 0; i < 9; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - a[i] - a[j] == 100) {
				ans = 1;
				a.erase(a.begin() + i);
				a.erase(a.begin() + j - 1);
				break;
			}
		}
		if (ans == 1) break;
	}

	sort(a.begin(), a.end());
	for (auto i : a) printf("%d\n", i);
}