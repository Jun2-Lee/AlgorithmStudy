#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		int house[200000] = { 0, };
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			house[i] = temp;
			house[i + n] = temp;
		}
		int answer = 0;
		int money = 0;
		for (int i = 0; i < m; i++) {
			money += house[i];
		}
		if (money < k) answer++;
		int start = 0, end = m - 1;
		while (start < n - 1) {
			money -= house[start];
			start++; end++;
			money += house[end];
			if (money < k) answer++;
		}
		money = 0;
		if (n == m) {
			for (int i = 0; i < n; i++) {
				money += house[i];
			}
			if (money < k) answer = 1;
		}
		cout << answer << endl;
	}
	return 0;
}
