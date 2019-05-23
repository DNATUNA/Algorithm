#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n = 0, num = 0;
	scanf("%d", &n);

	vector<int> check;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);

		while(1){
			if (num == 1) {
				check.push_back(1);
				break;
			}
			if (num % 2 == 1)check.push_back(1);
			else check.push_back(0);
			num /= 2;
		}
		for (int j = 0; j < check.size(); ++j) {
			if (check[j] == 1) printf("%d ", j);
		}
		printf("\n");
		check.clear();
	}
}