#include<cstdio>
#include<vector>

using namespace std;

int k, num;
vector<int> TestCase;
vector<int> PrintList(6);

void Backtraking(int pv, int count) {
	if (count == 6) {
		for (auto i : PrintList)
			printf("%d ", i);
		printf("\n");

		return;
	}

	else {
		for (int i = pv; i < k; ++i) {
			PrintList[count] = TestCase[i];
			Backtraking(i + 1, count + 1);
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &k);

		if (k == 0) break;
		else {
			for (int i = 0; i < k; ++i) {
				scanf("%d", &num);
				TestCase.push_back(num);
			}
			Backtraking(0,0);
		}
	}
}