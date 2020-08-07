#include<cstdio>
#include<algorithm>
#include<array>

using namespace std;

int main() {
	array<int, 3> num;

	for (int i = 0; i < 3; ++i)
		scanf("%d", &num[i]);

	sort(num.begin(), num.end());

	for (int i = 0; i < 3; ++i)
		printf("%d ", num[i]);
}