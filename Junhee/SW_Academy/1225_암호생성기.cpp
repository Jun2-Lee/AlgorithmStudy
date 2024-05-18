#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	for (int i = 0; i < 8; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}

	int cnt = 1;
	while (true) {
		int cur = q.front();
		q.pop();
		cur -= cnt;
		if (cur <= 0) {
			q.push(0);
			break;
		}
		else {
			q.push(cur);
		}
		cnt++;
		if (cnt > 5) {
			cnt = 1;
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}
