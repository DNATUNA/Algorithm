#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n, m, tmp;

	for (int i = 0; i < t; ++i) {
		int level[10] = { 0, };

		queue<pair<int, int>> printer;
		pair<int, int> want;

		cin >> n >> m;
		
		for (int a = 0; a < n; ++a) {
			cin >> tmp;
			printer.push(make_pair(a, tmp));
			level[tmp]++;
			if (a == m) want = make_pair(a, tmp);
		}

		int checkLevel = 9, ans = 0;

		while (1) {
			if (level[checkLevel]) {
				if (checkLevel == want.second) {
					if (printer.front().first == want.first) {
						ans++;
						break;
					}
					else {
						if (checkLevel == printer.front().second) {
							ans++;
							printer.pop();
							level[checkLevel]--;
						}
						else {
							printer.push(printer.front());
							printer.pop();
						}
					}
				}
				else {
					if (checkLevel == printer.front().second) {
						ans++;
						printer.pop();
						level[checkLevel]--;
					}
					else {
						printer.push(printer.front());
						printer.pop();
					}
				}
			}
			else {
				checkLevel--;
			}
		}
		cout << ans << "\n";
	}
}