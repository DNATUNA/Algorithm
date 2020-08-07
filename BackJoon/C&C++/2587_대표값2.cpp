#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int a[5] = { 0, };
	for (int i = 0; i < 5; ++i)
		scanf("%d", &a[i]);

	sort(a, a+5);

	printf("%d\n%d", (a[0] + a[1] + a[2] + a[3] + a[4]) / 5, a[2]);
}