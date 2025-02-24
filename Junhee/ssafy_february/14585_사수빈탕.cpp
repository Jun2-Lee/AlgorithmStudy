#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[301][301];
long long dp[301][301];
long long answer = -1;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = max(m - x - y, 0);
        if(x == 0 || y == 0) {
            dp[x][y] = max(m - x - y, 0);
            answer = max(answer, (long long)dp[x][y]);
        }
    }

    for(int i = 1; i < 301; i++) {
        for(int j = 1; j < 301; j++) {
            dp[i][j] = max(dp[i - 1][j] + map[i][j], dp[i][j - 1] + map[i][j]);
            answer = max(answer, (long long)dp[i][j]);
        }
    }
    cout << answer;
    return 0;
}
