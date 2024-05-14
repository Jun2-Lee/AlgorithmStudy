#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int min_c = 99999999999;
		int n, k;
		vector<int> pocket;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			pocket.push_back(temp);
		}
		sort(pocket.begin(), pocket.end(), greater<>());
		for (int j = 0; j <= n - k; j++) {
			int first = pocket[j];
			int last = pocket[j + k - 1];
			min_c = min(min_c, first - last);
		}
		cout << '#' << i << ' ' << min_c << endl;
	}
	return 0;
}
