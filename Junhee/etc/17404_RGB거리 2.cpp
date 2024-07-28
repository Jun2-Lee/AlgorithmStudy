#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 10000001

int n;
int color[3][1001];

int main() {
	cin >> n;
	int answer = INF;
	for (int i = 0; i < n; i++) {
		cin >> color[0][i] >> color[1][i] >> color[2][i];
	}

	for (int i = 0; i < 3; i++) {
		int dp[3][1001] = { 0, };
		dp[i][0] = color[i][0];
		dp[(i + 1) % 3][0] = INF;
		dp[(i + 2) % 3][0] = INF;
		

		for (int j = 1; j < n; j++) {
			dp[0][j] = color[0][j] + min(dp[1][j - 1], dp[2][j - 1]);
			dp[1][j] = color[1][j] + min(dp[0][j - 1], dp[2][j - 1]);
			dp[2][j] = color[2][j] + min(dp[0][j - 1], dp[1][j - 1]);
		}

		for (int j = 0; j < 3; j++) {
			if (i != j) answer = min(answer, dp[j][n - 1]);
		}
		
	}
	cout << answer;
	return 0;
}
