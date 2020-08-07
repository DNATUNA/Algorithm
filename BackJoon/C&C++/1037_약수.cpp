#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> list;
	int count = 0, tmp = 0;

	scanf("%d", &count);

	for (int i = 0; i < count; ++i) {
		scanf("%d", &tmp);
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());

	printf("%d", list.at(0) * list.back());
}