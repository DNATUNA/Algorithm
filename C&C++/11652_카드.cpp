#include<cstdio>
#include<algorithm>

using namespace std;

long long int num[1000001];

int main(){
	int n = 0, max = 0, check = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld", &num[i]);

	sort(num, num + n);

	long long int ans = num[0];

	for (int i = 1; i < n; ++i) {
		if (num[i - 1] == num[i])
			check++;
		else {
			if (max < check && !(ans > num[i - 1])) {
				max = check;
				ans = num[i - 1];
			}
			check = 1;
		}
	}
	if (max < check && !(ans > num[n - 1])) {
		max = check;
		ans = num[n - 1];
	}
	printf("%lld", ans);
}