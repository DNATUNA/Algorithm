#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (atoi(a.c_str()) > atoi(b.c_str()))
		printf("%s", a.c_str());
	else printf("%s", b.c_str());
}