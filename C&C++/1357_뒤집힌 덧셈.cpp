#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	string a, b;
	vector<char> num = {'0'};
	cin >> a >> b;

	if (a.size() > b.size()) {
		int i = 0;
		for (i; i < b.size(); ++i) {
			if (a[i] + b[i] + num[i] - '0' - '0' - '0' > 9) {
				num[i] += a[i] + b[i] - '0' - '0' - 10;
				num.push_back('1');
			}
			else {
				num[i] += a[i] + b[i] - '0' - '0';
				num.push_back('0');
			}
		}
		for (i; i < a.size(); ++i) {
			if (a[i] + num[i] - '0' - '0' > 9) {
				num[i] += a[i] - '0' - 10;
				num.push_back('1');
			}
			else {
				num[i] += a[i] - '0';
				num.push_back('0');
			}
		}
	}
	else {
		int i = 0;
		for (i; i < a.size(); ++i) {
			if (a[i] + b[i] + num[i] - '0' - '0' - '0' > 9) {
				num[i] += a[i] + b[i] - '0' - '0' - 10;
				num.push_back('1');
			}
			else {
				num[i] += a[i] + b[i] - '0' - '0';
				num.push_back('0');
			}
		}
		for (i; i < b.size(); ++i) {
			if (b[i] + num[i] - '0' - '0' > 9) {
				num[i] += b[i] - '0' - 10;
				num.push_back('1');
			}
			else {
				num[i] += b[i] - '0';
				num.push_back('0');
			}
		}

	}

	while (num[num.size() - 1] == '0') num.pop_back();
	reverse(num.begin(), num.end());
	while (num[num.size() - 1] == '0') num.pop_back();
	reverse(num.begin(), num.end());

	for (int i = 0; i < num.size(); ++i)
		printf("%c", num[i]);
}

/*
#include <stdio.h>
int rv(int n){
	int r=0;
	while(n>0){
		r=r*10+n%10;
		n/=10;
	}
	return r;
}
main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",rv(rv(a)+rv(b)));
}
*/