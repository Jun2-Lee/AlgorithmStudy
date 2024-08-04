#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	int dp[10001] = { 0, };
	int money[101] = { 0, };
	cin >> n >> k;
	for (int i = 0; i <= k; i++) {
		dp[i] = 999999;
	}
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		money[i] = temp;
		if(temp < 10001)
			dp[temp] = 1;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - money[j] >= 0) {
				dp[i] = min(dp[i], dp[i - money[j]] + 1);
			}
		}
	}
	/*for (int i = 1; i <= k; i++) {
		cout << dp[i] << " ";
	}*/
	if (dp[k] != 999999) cout << dp[k] << endl;
	else cout << -1 << endl;
	return 0;
}
