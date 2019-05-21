#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int a = 0, b = 0, num1 = 0, num2 = 0;

	for (int i = 0; i < 3; ++i) {
		scanf("%d%d", &a, &b);
		num1 ^= a, num2 ^= b;
	}
	printf("%d %d", num1, num2);
}