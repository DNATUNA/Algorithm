#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int num = 0, sum=0;
	scanf("%d", &num);

	vector<int> v(num);

	for (int i = 0; i < num; ++i) {
		scanf("%1d", &v[i]);
		sum += v[i];
	}

	printf("%d", sum);
}