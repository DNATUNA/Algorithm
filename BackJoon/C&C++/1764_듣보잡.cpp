#include<iostream>
#include<unordered_map>
#include<string>
#include<map>

using namespace std;

int main() {
	unordered_map<string, int> list;

	int n, m;
	cin >> n >> m;

	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		list[tmp]++;
	}

	int ans = 0;
	map<string, int> ansList;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		if (list[tmp]) {
			ans++;
			ansList[tmp]++;
		}
	}
	cout << ans << "\n";

	for (auto s : ansList)
		cout << s.first << "\n";
}