#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);

	string st;

	for (int i = 0; i < n; ++i) {
		cin >> st;

		printf("String #%d\n", i + 1);
		for (int j = 0; j < st.length(); ++j) {
			if (st[j] == 'Z') printf("A");
			else printf("%c", st[j] + 1);
		}
		printf("\n\n");
	}
}