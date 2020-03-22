#include<cstdio>
#include<vector>

using namespace std;

int Factorial(int n) {
	if(n == 0) return 1;

	int ans = 1;
	for (int i = n; i > 0; --i) ans *= i;

	return ans;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int ans = Factorial(n) / (Factorial(k) * Factorial(n - k));

	printf("%d", ans);
}
