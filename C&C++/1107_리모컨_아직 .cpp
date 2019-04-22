#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int num = 0, count = 0, tmp = 0;
	scanf("%d%d", &num, &count);
	
	vector<int> remote = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < count; ++i) {
		scanf("%d", &tmp);
		remote.erase(remote.begin()+tmp-i);
	}

	sort(remote.begin(), remote.end());

	int ans = 0;


}