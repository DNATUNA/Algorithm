#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	cin >> n;

	queue<int> list;
	string order;

	for (int i = 0; i < n; ++i) {
		cin >> order;

		if (!order.compare("push")) {
			cin >> num;
			list.push(num);
		}
		else if (!order.compare("pop")) {
			if (list.empty()) cout << "-1\n";
			else {
				cout << list.front() << "\n";
				list.pop();
			}
		}
		else if (!order.compare("size")) {
			cout << list.size() << "\n";
		}
		else if (!order.compare("empty")) {
			if (list.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (!order.compare("front")) {
			if (list.empty()) cout << "-1\n";
			else cout << list.front() << "\n";
		}
		else if (!order.compare("back")) {
			if (list.empty()) cout << "-1\n";
			else cout << list.back() << "\n";
		}
	}
}