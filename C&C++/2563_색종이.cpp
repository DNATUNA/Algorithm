#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);

	int ans = 0, a = 0, b = 0;
	int board[101][101] = { 0, };
	while(n--) {
		scanf("%d%d", &a, &b);

		for (int i = a; i < a + 10; ++i)
			for (int j = b; j < b + 10; ++j)
				ans += !board[i][j]++;
	}
	printf("%d", ans);
}