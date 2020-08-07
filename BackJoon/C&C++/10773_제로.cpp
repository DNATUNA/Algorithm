#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> num;
	int k, n;

	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> n;
		if (n == 0) num.pop();
		else num.push(n);
	}

	int ans = 0;
	while (!num.empty()) {
		ans += num.top();
		num.pop();
	}
	cout << ans;
}