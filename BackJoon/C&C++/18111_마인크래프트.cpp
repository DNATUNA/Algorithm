#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	int list[257] = { 0, }, tmp, min = 257, max = 0;
	for (int i = 0; i < n * m; ++i) {
		cin >> tmp;
		list[tmp]++;
		if (tmp > max)max = tmp;
		else if (tmp < min)min = tmp;
	}

	int height = 0, block = 0, ansTime = 2100000000, ansFloor = 0;
	for (int i = min; i <= max; ++i) {
		int inven = b;
		int time = 0;
		int check = 1;
		for (int j = i + 1; j <= max; ++j) {
			inven += list[j] * (j - i);
			time += list[j] * 2 * (j - i);
		}
		for (int j = min; j < i; ++j) {
			if (i == 0)break;
			time += list[j] * (i - j);
			inven -= list[j] * (i - j);
			if (inven < 0) {
				check = 0;
				break;
			}
		}
		if (check) {
			if (ansTime >= time) {
				ansTime = time;
				if (ansFloor < i)
					ansFloor = i;
			}
		}
	}
	cout << ansTime << " " << ansFloor;
}