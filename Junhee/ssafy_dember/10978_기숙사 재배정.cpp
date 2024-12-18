#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
long long dp[21];

int main() {
    cin >> t;
    dp[2] = 1;
    for(int i = 3; i < 21; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    for(int test = 0; test < t; test++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
