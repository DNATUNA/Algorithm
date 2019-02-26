#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int n = 0, a[50] = { '\0', }, b[50] = { '\0', }, ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

	sort(a, a + n); sort(b, b + n);
	for (int i = 0; i < n; ++i) ans += a[i] * b[n - i - 1];
	printf("%d", ans);
}