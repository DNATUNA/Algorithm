#include<cstdio>
#include<iostream>
#include<regex>
#include<string>

using namespace std;

string s1, s2, s3, s4, s5;

int main() {
	
	int stack[5] = { 0, }, i = 0, total = 0;
	regex range("[0-9][a-z][A-Z]");

	cin >> s1 >> s2 >> s3 >> s4 >> s5;

	while (total != 5) {
		if (i < s1.length()) printf("%c", s1[i]);
		else if (stack[0] == 0) stack[0]++;

		if (i < s2.length()) printf("%c", s2[i]);
		else if (stack[1] == 0) stack[1]++;

		if (i < s3.length()) printf("%c", s3[i]);
		else if (stack[2] == 0) stack[2]++;

		if (i < s4.length()) printf("%c", s4[i]);
		else if (stack[3] == 0) stack[3]++;

		if (i < s5.length()) printf("%c", s5[i]);
		else if (stack[4] == 0) stack[4]++;

		total = stack[0] + stack[1] + stack[2] + stack[3] + stack[4];
		i++;
	}
}