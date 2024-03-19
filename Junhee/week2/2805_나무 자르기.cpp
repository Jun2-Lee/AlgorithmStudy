#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trees;

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tree;
		cin >> tree;
		trees.push_back(tree);
	}
	sort(trees.begin(), trees.end());

	int start = 0, end = trees[n-1];
	int answer = 0;

	while (start <= end) {
		long long sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < n; i++) {
			sum += max(0, trees[i] - mid);
		}

		if(m <= sum) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << answer;

	return 0;
}
