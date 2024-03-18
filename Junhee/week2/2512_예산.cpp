#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int> budget;

	// 값 입력부
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t_budget;
		cin >> t_budget;
		budget.push_back(t_budget);
	}
	cin >> m;

	sort(budget.begin(), budget.end());

	int start = 0, end = budget[n-1];
	int answer = 0;
	while (start <= end) {
		int sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			sum += min(mid, budget[i]);
		}
		if (sum <= m) {
			answer = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << answer;

	return 0;
}
