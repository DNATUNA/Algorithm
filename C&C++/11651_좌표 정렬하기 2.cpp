#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> list(n);

	for (int i=0; i<n; ++i)
		cin >> list[i].first >> list[i].second;

	sort(list.begin(), list.end(), compare);

	for (auto i : list)
		cout << i.first << " " << i.second << "\n";
}