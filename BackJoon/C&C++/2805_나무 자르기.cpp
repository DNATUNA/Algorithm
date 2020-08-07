#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, m;
	cin >> n >> m;

	vector<long long int> list(n);

	for (int i = 0; i < n; ++i)
		cin >> list[i];

	sort(list.begin(), list.end());
	long long int left = 0, right = list[list.size() - 1];
	long long int max = 0;

	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int ans = 0;

		for (auto i : list)
			if (i > mid)
				ans += i - mid;

		if (ans >= m) {
			left = mid + 1;
			if (max < mid) max = mid;
		}
		else
			right = mid - 1;
	}
	cout << max;
}