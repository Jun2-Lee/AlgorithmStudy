#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct road {
	int start;
	int end;
	int len;
};

int dp[10001];

vector<road> fast_road;

int main() {
	int n, d;

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		road temp_r;
		cin >> temp_r.start >> temp_r.end >> temp_r.len;
		fast_road.push_back(temp_r);
	}

	for (int i = 1; i <= d; i++) {
		for (int j = 0; j < fast_road.size(); j++) {
			if (fast_road[j].end == i) {
				if(dp[i] == 0)
					dp[i] = min(dp[i - 1] + 1, dp[fast_road[j].start] + fast_road[j].len);
				else
					dp[i] = min(dp[i - 1] + 1, min(dp[i], dp[fast_road[j].start] + fast_road[j].len));
			}
		}
		if (dp[i] == 0) dp[i] = dp[i - 1] + 1;
	}

	/*for (int i = 0; i <= d; i++) {
		cout << dp[i] << " ";
	}*/
	cout << dp[d];

	return 0;
}
