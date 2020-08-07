#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string white = "WBWBWBWB";
string black = "BWBWBWBW";

int main() {

	int x = 0, y = 0;

	scanf("%d%d", &y, &x);

	vector<string> chess(y);
	string tmp;

	for (int i = 0; i < y; ++i)
		cin >> chess[i];

	int minCount = 199999999, checkWhite = 1, checkBlack = 1, minWhite = 0, minBlack = 0;

	for (int a = 0; a < y - 7; ++a) {
		for (int b = 0; b < x - 7; ++b) {				// 입력된 예제에서 비교할 첫 번째 인덱스 찾는 루프

			for (int i = 0; i < 8; ++i) {				// 8*8 크기로 돌기
				for (int j = 0; j < 8; ++j) {

					if (checkWhite == 1) {				// 하얀색 시작일 때 체크
						if (chess[a + i][b + j] != white[j]) minWhite++;
					}
					else {
						if (chess[a + i][b + j] != black[j]) minWhite++;
					}

					if (checkBlack == 1) {				// 검정색 시작일 때 체크
						if (chess[a + i][b + j] != black[j]) minBlack++;
					}
					else {
						if (chess[a + i][b + j] != white[j]) minBlack++;
					}
				}
				checkWhite ^= 1;
				checkBlack ^= 1;
			}
			minCount = min(minCount, minWhite);
			minCount = min(minCount, minBlack);
			minWhite = 0;
			minBlack = 0;
		}
	}

	printf("%d", minCount);
}