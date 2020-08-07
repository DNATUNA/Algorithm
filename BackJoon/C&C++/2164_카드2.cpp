#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> card;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		card.push(i);

	while (card.size() != 1)
	{
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front();
}
