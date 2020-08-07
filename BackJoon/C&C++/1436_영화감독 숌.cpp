#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n, check = 1;
	scanf("%d", &n);

	int num = 666;
	string numString;
	while (n != check) {
		num++;

		numString = to_string(num);
		if (numString.find("666") != -1) check++;
	}
	printf("%d", num);
}
