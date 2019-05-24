#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
	string n, m;
	cin >> n >> m;
	
	int ptr = 0;
	if (n.length() * atoi(n.c_str()) < atoi(m.c_str())) {
		for (int i = 0; i < n.length() * atoi(n.c_str()); ++i) {
			printf("%c", n[ptr]);
			ptr++;
			if (ptr == n.length()) ptr = 0;
		}
	}
	else {
		for (int i = 0; i < atoi(m.c_str()); ++i) {
			printf("%c", n[ptr]);
			ptr++;
			if (ptr == n.length()) ptr = 0;
		}
	}
}