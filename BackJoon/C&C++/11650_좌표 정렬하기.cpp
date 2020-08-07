#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> list(n);

	for (int i=0; i<n; ++i)
		cin >> list[i].first >> list[i].second;

	sort(list.begin(), list.end());

	for (auto i : list)
		cout << i.first << " " << i.second << "\n";
}