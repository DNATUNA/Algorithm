#include<iostream>
#include<string>

using namespace std;

int main() {
	string text;
	
	while (1) {
		cin >> text;

		if (!text.compare("0")) break;

		int check = 1;
		for (int i = 0; i < text.length()/2; ++i) {
			if (text[i] != text[text.length() - i - 1]) {
				check = 0;
				break;
			}
		}
		if (check) cout << "yes\n";
		else cout << "no\n";
	}
}