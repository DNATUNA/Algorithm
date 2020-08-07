#include<iostream>
#include<vector>

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int num;
	cin >> num;
	vector<int> dp(num + 1);

	for (int i = 0; i <= num; ++i) dp[i] = i;
	for (int i = 2; i <= num; ++i)
		for (int j = 2; j * j <= i; ++j)
			dp[i] = Min(dp[i], dp[i - j * j] + 1);

	cout << dp[num];
}