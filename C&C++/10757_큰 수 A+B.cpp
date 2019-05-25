#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int i = 0;
	vector<char> ans = { 48 };
	if (a.length() > b.length()) {
		while (i < b.length()) {
			if (ans[i] + a[i] + b[i] - 48 - 48 < 58) {
				ans[i] += a[i] + b[i] - 48 - 48;
				ans.push_back(48);
			}
			else {
				ans[i] += a[i] + b[i] - 48 - 48 - 10;
				ans.push_back(49);
			}
			i++;
		}
		while (i < a.length()) {
			if (ans[i] + a[i] - 48 < 58) {
				ans[i] += a[i] - 48;
				ans.push_back(48);
			}
			else {
				ans[i] += a[i] - 48 - 10;
				ans.push_back(49);
			}
			i++;
		}
	}
	else {
		while (i < a.length()) {
			if (ans[i] + a[i] + b[i] - 48 - 48 < 58) {
				ans[i] += a[i] + b[i] - 48 - 48;
				ans.push_back(48);
			}
			else {
				ans[i] += a[i] + b[i] - 48 - 48 - 10;
				ans.push_back(49);
			}
			i++;
		}
		while (i < b.length()) {
			if (ans[i] + b[i] - 48 < 58) {
				ans[i] += b[i] - 48;
				ans.push_back(48);
			}
			else {
				ans[i] += b[i] - 48 - 10;
				ans.push_back(49);
			}
			i++;
		}
	}
	if (ans[ans.size() - 1] == 48) ans.pop_back();

	for (int i = ans.size() - 1; i >= 0; --i)
		printf("%c", ans[i]);
}