#include<iostream>
#include<vector>

using namespace std;

vector<int> list(1000001);

int Min(int a, int b) { return list[a] < list[b] ? a : b; }
int Check(int i) {
	if ((i % 3 == 0) && (i % 2 == 0)) {
		int min = Min(i / 3, i / 2);
		min = Min(i - 1, min);
		return list[min] + 1;
	}
	else if (i % 3 == 0) {
		int min = Min(i / 3, i - 1);
		return list[min] + 1;
	}
	else if (i % 2 == 0) {
		int min = Min(i / 2, i - 1);
		return list[min] + 1;
	}
	else return list[i - 1] + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	int n;
	cin >> n;
	
	list[1] = 0;
	list[2] = 1;
	list[3] = 1;
	for (int i = 4; i <= n; ++i)
		list[i] = Check(i);
	
	cout << list[n];
}