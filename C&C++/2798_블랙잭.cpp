#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> card(n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &card[i]);

	int ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i+1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (ans < card[i] + card[j] + card[k]) {
					if (m >= card[i] + card[j] + card[k]) {
						ans = card[i] + card[j] + card[k];
					}
				}
			}
		}
	}

	printf("%d", ans);
}