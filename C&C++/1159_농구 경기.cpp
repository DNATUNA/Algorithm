#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int list[26];

int main() {
	int n = 0, check = 0;
	scanf("%d", &n);

	string name;
	for (int i = 0; i < n; ++i) {
		cin >> name;

		list[name[0] - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
		if (list[i] >= 5) printf("%c", i + 'a');
		else check++;

	if (check == 26) printf("PREDAJA");
}