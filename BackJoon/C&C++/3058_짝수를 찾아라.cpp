#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n = 0, sum = 0, tmp = 0, min = 1000;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 7; ++j) {
			scanf("%d", &tmp);
			if ((tmp % 2) == 0) {
				sum += tmp;
				if (min > tmp)
					min = tmp;
			}			
		}
		printf("%d %d\n", sum, min);		
		sum = 0, min = 1000;
	}
}