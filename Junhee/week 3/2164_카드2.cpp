#include <queue>
#include <iostream>

using namespace std;

int main() {
	queue<int> cards;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cards.push(i);
	}
	int card = 0;
	while (cards.size() != 1) {
		cards.pop();
		card = cards.front();
		cards.push(card);
		cards.pop();
	}
	cout << cards.front();

	return 0;
}
