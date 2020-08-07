#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n = 0;

	scanf("%d", &n);

	vector<int> num(n);

	for (int i = 0; i < n; ++i)
 		scanf("%d", &num[i]);

	sort(num.begin(), num.end());

	for (int i = 0; i < n; ++i)
		printf("%d", num[i]);

	
}