#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void binarySearch(vector<int> &A, int start, int end, int find) {
	if (start > end)
		cout << "0\n";
	else if (A[(start + end) / 2] == find)
		cout << "1\n";
	else if (A[(start + end) / 2] > find)
		binarySearch(A, start, ((start + end) / 2) - 1, find);
	else
		binarySearch(A, ((start + end) / 2) + 1, end, find);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i];

	sort(A.begin(), A.end());

	int m;
	cin >> m;

	vector<int> B(m);

	for (int i = 0; i < m; ++i)
		cin >> B[i];

	for (auto i : B)
		binarySearch(A, 0, n - 1, i);
}