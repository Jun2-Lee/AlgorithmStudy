#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int answer = 0;
	int buildings[1001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}
	for (int i = 2; i < n - 2; i++) {
		int left = max(buildings[i - 1], buildings[i - 2]);
		int right = max(buildings[i + 1], buildings[i + 2]);
		int curr = buildings[i];
		if (curr > left && curr > right) {
			answer += min(curr - left, curr - right);
		}
	}
	cout << answer;
	return 0;
}
