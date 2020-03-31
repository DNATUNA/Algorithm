#include<iostream>
#include<string>

using namespace std;


int main() {
	string text;
	int n;
	cin >> n >> text;

	long long int ans = 0, tmp = 1, M = 1234567891;
	for (int i = 0; i < n; ++i) {
		ans += tmp * (text[i] - 'a' + 1);
		ans %= M;
		tmp *= 31;
		tmp %= M;
	}
	cout << ans;

	return 0;
}