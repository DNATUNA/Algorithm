#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n1 = 0, n2 = 0, tmp = 0;
	vector<int> num;

	scanf("%d", &n1);

	for (int i = 0; i < n1; ++i) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}


	sort(num.begin(), num.end());

	scanf("%d", &n2);

	

	for (int i = 0; i < n2; ++i) {
		scanf("%d", &tmp);

		int numSize = num.size(), mid = numSize / 2, start = 0, end = numSize;

		while (numSize!=0)
		{
			if (tmp == num[mid]) {
				printf("1 ");
				break;
			}
			else if (tmp < num[mid]) {
				end = mid - 1;
				mid = (start + end) / 2;
			}
			else if (tmp > num[mid]) {
				start = mid + 1;
				mid = (start + end) / 2;
			}
			numSize /= 2;
		}
		if (numSize == 0)printf("0 ");
	}
}