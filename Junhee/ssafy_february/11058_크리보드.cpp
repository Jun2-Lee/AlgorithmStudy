#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[101];
int n;

int main()
{
    cin >> n;

    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i-1]+1, (long long) i);
        for(int j = i - 3; j >= 1; j--)
        {
            dp[i] = max(dp[i], dp[j] * (i - j - 1));
        }
    }

    cout << dp[n];

}
