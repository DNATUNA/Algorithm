#include<iostream>
#include<string>
#include<deque>
#include<sstream>

using namespace std;

int main() {
	int n;
	cin >> n;

	string order, numString;
	int len;
	for (int i = 0; i < n; ++i) {
		int check = 0;
		cin >> order >> len >> numString;

		numString.erase(numString.begin());
		numString.erase(numString.end() - 1);

		deque<int> numArray;

		stringstream ss(numString);
		for (int i; ss >> i;) {
			numArray.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		int reverseCheck = 0;
		for (auto a : order) {
			if (a == 'R') {
				reverseCheck ^= 1;
			}
			else {
				if (numArray.size() == 0) {
					check = 1;
					break;
				}
				if (reverseCheck)
					numArray.pop_back();
				else
					numArray.pop_front();
			}
		}
		if (check)
			cout << "error\n";
		else {
			cout << "[";
			while (1) {
				if (reverseCheck) {
					if (numArray.size() == 1) {
						cout << numArray.back() << "]\n";
						break;
					}
					else if (numArray.size() == 0) {
						cout << "]\n";
						break;
					}
					else {
						cout << numArray.back() << ",";
						numArray.pop_back();
					}
				}
				else {
					if (numArray.size() == 1) {
						cout << numArray.front() << "]\n";
						break;
					}
					else if (numArray.size() == 0) {
						cout << "]\n";
						break;
					}
					else {
						cout << numArray.front() << ",";
						numArray.pop_front();
					}
				}
			}
		}
	}
}