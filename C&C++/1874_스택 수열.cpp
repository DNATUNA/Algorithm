#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, list = 1;
	cin >> n;

	stack<int> order;
	vector<char> ans;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num >= list) {
			while (num >= list) {
				ans.push_back('+');
				order.push(list);
				list++;
			}
			ans.push_back('-');
			order.pop();
		}
		else {
			if (num == order.top()) {
				ans.push_back('-');
				order.pop();
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}

	for (auto i : ans)
		cout << i << "\n";
}