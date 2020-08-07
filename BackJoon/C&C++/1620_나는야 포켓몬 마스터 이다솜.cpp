#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;

bool CheckInteger(string str) {
	for (auto c : str)
		if (c < '0' || '9' < c) return false;
	return true;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> list;
	string name[100000];

	for (int i = 0; i < n; ++i) {
		cin >> name[i];
		list[name[i]] = i;
	}

	string text;
	for (int i = 0; i < m; ++i) {
		cin >> text;

		if (CheckInteger(text)) {
			int num = 0, R = 1;
			for (int a = 0; a < text.length(); ++a) {
				num += (text[text.length() - 1 - a] - '0') * R;
				R *= 10;
			}
			cout << name[num - 1] << "\n";
		}
		else {
			cout << list[text] + 1 << "\n";
		}
	}
}