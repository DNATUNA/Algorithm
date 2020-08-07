#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num[10001] = { 0, };
	int n, tmp;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		num[tmp]++;
	}

	for (int i = 1; i < 10001; ++i) {
		for (int a = 0; a < num[i]; ++a)
			cout << i << "\n";
	}
}