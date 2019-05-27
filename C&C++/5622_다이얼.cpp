#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int ans = 0;
	string a;
	cin >> a;

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] >= 'A' && a[i] <= 'C') ans += 3;
		else if (a[i] >= 'D' && a[i] <= 'F') ans += 4;
		else if (a[i] >= 'G' && a[i] <= 'I') ans += 5;
		else if (a[i] >= 'J' && a[i] <= 'L') ans += 6;
		else if (a[i] >= 'M' && a[i] <= 'O') ans += 7;
		else if (a[i] >= 'P' && a[i] <= 'S') ans += 8;
		else if (a[i] >= 'T' && a[i] <= 'V') ans += 9;
		else if (a[i] >= 'W' && a[i] <= 'Z') ans += 10;
	}

	printf("%d", ans);
}