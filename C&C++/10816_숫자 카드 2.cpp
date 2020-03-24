#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, tmp;
	cin >> n;

	unordered_map<int, int> list;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (list[tmp]) list[tmp]++;
		else list[tmp] = 1;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (list[tmp]) cout << list[tmp] << ' ';
		else cout << "0 ";
	}
}