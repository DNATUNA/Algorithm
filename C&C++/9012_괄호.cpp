#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {

	int time = 0, ans = 0;
	scanf("%d", &time);

	vector<string> PS(time);

	for (int i = 0; i < time; ++i) {
		cin >> PS[i];

		for (int j = 0; j < PS[i].length(); ++j) {
			if (j < 50 && PS[i][j] == '(') ans++;
			else if (j < 50 && ans != 0 && PS[i][j] == ')') ans--;
			else {
				ans = -1;
				break;
			}
		}
		if (ans == 0) printf("YES\n");
		else printf("NO\n");
		ans = 0;
	}
}