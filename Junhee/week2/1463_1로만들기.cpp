#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {

	int n;
	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		if (i % 6 == 0) {
			dp[i] = min(dp[i - 1] + 1,min(dp[i / 2] + 1, dp[i / 3] + 1));
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		}
		else
			dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n];

	return 0;
}
