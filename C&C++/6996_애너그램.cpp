#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);

	string st1, st2;

	for (int i = 0; i < n; ++i) {

		int check1[27] = { 0, }, check2[27] = { 0, }, a = 0;

		cin >> st1 >> st2;

		if (st1.length() != st2.length()) {
			printf("%s & %s are NOT anagrams.\n", st1.c_str(), st2.c_str());
			continue;
		}
		else {
			for (int j = 0; j < st1.length(); ++j)
				check1[st1[j]-97]++, check2[st2[j]-97]++;
			for (int j = 0; j < 26; ++j) {
				if (check1[j] != check2[j]) {
					printf("%s & %s are NOT anagrams.\n", st1.c_str(), st2.c_str());
					a++;
					break;
				}
			}
			if(a==0)	printf("%s & %s are anagrams.\n", st1.c_str(), st2.c_str());
			a = 0;
		}
	}
}