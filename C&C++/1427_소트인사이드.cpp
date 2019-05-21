#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	char a = {};
	vector<char> b;

	while (1) {
		scanf("%1c", &a);
		if (a == '\n') break;
		b.push_back(a);
	}
	sort(b.begin(), b.end(), desc);

	for (auto i = b.begin(); i != b.end(); ++i)
		printf("%c", *i);
}