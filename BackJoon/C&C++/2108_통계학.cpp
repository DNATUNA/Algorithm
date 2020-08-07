#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double sum = 0;
	cin >> n;

	vector<int> list(n);
	map<int, int> count;
	vector<pair<int, int>> countCheck(8001);

	for (int i = 0; i < n; ++i) {
		cin >> list[i];
		if (count[list[i]]) count[list[i]]++;
		else count[list[i]] = 1;
		sum += list[i];
	}

	cout << floor((sum / n) + 0.5) << "\n";

	sort(list.begin(), list.end());
	cout << list[n / 2] << "\n";

	if (n == 1) {
		cout << list[0] << "\n" << "0";
	}
	else {
		int a = 0;
		for (auto i : count) {
			countCheck[a] = make_pair(i.first, i.second);
			a++;
		}

		sort(countCheck.begin(), countCheck.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second) return a.first < b.first;
			else return a.second > b.second;
			});

		//for (auto i : countCheck)
		//	cout << "LOG LOG LOG: " << i.first << " " << i.second << "\n";

		if (countCheck[0].second == countCheck[1].second) cout << countCheck[1].first << "\n";
		else cout << countCheck[0].first << "\n";
		cout << list[list.size() - 1] - list[0];
	}
}
