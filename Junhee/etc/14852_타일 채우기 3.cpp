#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long dp[1000000];
long long sum[1000000];
int main()
{
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    sum[0] = 1;
    sum[1] = 3;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3 + sum[i - 3] * 2) % 1000000007;
        sum[i] = (sum[i - 1] + dp[i]) % 1000000007;
    }
    cout << dp[n] % 1000000007;
}
