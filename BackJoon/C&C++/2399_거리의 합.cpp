#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n;
	long long int tmp, ans = 0;
	vector<long long int> num;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &tmp);
		num.push_back(tmp);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (num[i] > num[j]) ans += num[i] - num[j];
			else ans += num[j] - num[i];
		}
	} 

	printf("%lld", ans);
}