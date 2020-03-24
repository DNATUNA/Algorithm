#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

	deque<int> list;
	int n, num;
	string order;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> order;

		if (!order.compare("push_front")) {
			cin >> num;
			list.push_front(num);
		}
		else if (!order.compare("push_back")) {
			cin >> num;
			list.push_back(num);
		}
		else if (!order.compare("pop_front")) {
			if (list.empty()) cout << "-1\n";
			else {
				cout << list.front() << "\n";
				list.pop_front();
			}
		}
		else if (!order.compare("pop_back")) {
			if (list.empty()) cout << "-1\n";
			else {
				cout << list.back() << "\n";
				list.pop_back();
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
