#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, string> list;

	int n, m;
	cin >> n >> m;

	string id, passwd;
	for (int i = 0; i < n; ++i) {
		cin >> id >> passwd;
		list[id] = passwd;
	}
	for (int i = 0; i < m; ++i) {
		cin >> id;
		cout << list[id] << "\n";
	}
}