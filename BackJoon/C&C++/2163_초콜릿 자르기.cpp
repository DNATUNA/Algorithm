#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	vector<string> list;

	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		list.push_back(str);
	}

	int min, charMin;
	string tmp;
	for (int i = 0; i < list.size() - 1; ++i) {
		min = i;

		for (int j = i + 1; j < list.size(); ++j) {
			if (list[min].length() > list[j].length())
				min = j;
			else if (list[min].length() == list[j].length()) {
				if (!list[min].compare(list[j])) {
					list.erase(list.begin() + j);
					--j;
				}
				else {
					for (int i = 0; i < list[min].length(); ++i) {
						if (list[min][i] > list[j][i]) {
							min = j;
							break;
						}
						else if (list[min][i] < list[j][i])
							break;
					}
				}
			}
		}

		if (i != min) {
			tmp = list[i];
			list[i] = list[min];
			list[min] = tmp;
		}

	}

	for (auto i : list)
		printf("%s\n", i.c_str());
}