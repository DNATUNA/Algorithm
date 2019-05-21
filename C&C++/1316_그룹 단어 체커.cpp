#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);

	int stack = n;
	string st;

	for (int i = 0; i < n; ++i) {
		int check[26] = { 0, };
		cin >> st;
		for (int i = 0; i < st.length(); ++i) {
			if (i == 0) check[st[i] - 97]++;
			else {
				if (st[i - 1] == st[i]) continue;
				else {
					if (check[st[i] - 97] == 1) {
						stack--;
						break;
					}
					else	check[st[i] - 97]++;
				}
				
			}
		}
	}
	printf("%d", stack);
}