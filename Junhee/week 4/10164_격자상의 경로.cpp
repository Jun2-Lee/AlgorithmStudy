#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int x, y;
int dp[16][16];



int main() {
	int dest;
	cin >> n >> m >> dest;
	
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < m; i++) {
		dp[0][i] = 1;
	}

	if (dest != 0) {
		dest--;
		x = dest / m; y = dest % m;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		for (int i = x; i < n; i++) {
			dp[i][y] = dp[x][y];
		}
		for (int j = y; j < m; j++) {
			dp[x][j] = dp[x][y];
		}

		for (int i = x + 1; i < n; i++) {
			for (int j = y + 1; j < m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	else {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[n - 1][m - 1];
	return 0;
}
