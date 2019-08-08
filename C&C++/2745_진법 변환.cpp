#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
	string text;
	long long int num;
	cin >> text >> num;

	long long ans = 0, stack = 0;

	if (text[0] >= '0' && text[0] <= '9')
		ans = (long long int)(text[0] - '0');
	else	
		ans = (long long int)(text[0] - 55);

	for (long long int i = 1; i < (long long int)text.length(); ++i) {
		if (text[i] >= '0' && text[i] <= '9')
			ans += (long long int)( pow(num, i) * (text[i] - '0'));
		else
			ans += (long long int)( pow(num, i) * (text[i] - 55));
	}

	printf("%lld", ans);
}