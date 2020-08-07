#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);

	string num, re;
	
	for (int i = 0; i < n; ++i) {
		int check = 0, idx = 0;
		vector<char> sum;
		cin >> num;
		re = num;
		reverse(re.begin(), re.end());

		for (int j = 0; j < num.length(); ++j) {
			if (j == 0) {
				if (re[j] + num[j] - 96 > 9) {
					sum.push_back(1);
					sum.push_back(re[j] + num[j] - 106);
					idx++;
				}
				else sum.push_back(re[j] + num[j] - 96);
			}
			else {
				if (re[j] + num[j] - 96 > 9) {
					sum[idx - 1]++;
					sum.push_back(re[j] + num[j] - 106);
					idx++;
				}
				else sum.push_back(re[j] + num[j] - 96);
			}
			idx++;
		}
		for (int j = 0; j < sum.size()/2; ++j)
			if (sum[j] != sum[sum.size() - j - 1]) check++;

		if (check != 0)printf("NO\n");
		else printf("YES\n");
	}
}