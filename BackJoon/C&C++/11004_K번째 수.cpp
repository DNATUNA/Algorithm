#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n = 0, want = 0;
	scanf("%d%d", &n, &want);

	vector<int> num(n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	
	sort(num.begin(), num.end());

	printf("%d", num[want - 1]);
}