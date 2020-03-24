#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int k, n;

	cin >> k >> n;

	vector<long long int> list(k);
	for (int i = 0; i < k; ++i)
		cin >> list[i];

	sort(list.begin(), list.end());

	long long int start = 1, end = list[list.size() - 1];
	long long int sum = 0, mid, max = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		for (auto i : list)
			sum += i / mid;

		if (sum >= n) {
			start = mid + 1;
			if (mid > max) max = mid;
		}
		else if (sum < n)
			end = mid - 1;

		sum = 0;
	}

	cout << max;
}