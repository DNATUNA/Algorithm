#include<iostream>
#include<stack>
#include<string>

using namespace std;

string text;
stack<char> check;
int boolInt = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		getline(cin, text);

		if (!text.compare(".")) break;

		for (auto i : text) {
			if (i == '(' || i == '[')
				check.push(i);
 			else if (i == ')') {
				if (check.size() == 0) boolInt = 0;
				else if (check.top() == '(') check.pop();
				else boolInt = 0;
			}
			else if (i == ']') {
				if (check.size() == 0) boolInt = 0;
				else if (check.top() == '[') check.pop();
				else boolInt = 0;
			}
		}
		if (boolInt && check.empty()) cout << "yes\n";
		else cout << "no\n";

		boolInt = 1;
		check = {};
	}
}