#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first)
		return a.first < b.first;
	else
		return a.second.first < b.second.first;
}
int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, pair<int, string>>> list(n);

	for (int i = 0; i < n; ++i) {
		list[i].first = i;
		cin >> list[i].second.first >> list[i].second.second;
	}

	sort(list.begin(), list.end(), compare);

	for (auto i : list)
		cout << i.second.first << " " << i.second.second << "\n";
}