#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k;
int dp[10001];
vector<pair<int, int>> coin;

int main() {
    cin >> t >> k;
    for(int i = 0; i < k; i++) {
        int p, n;
        cin >> p >> n;
        coin.push_back({p, n});
    }
    dp[0] = 1;
    for(int i = 0; i < coin.size(); i++) {
        for(int j = t; j >= 0; j--) {
            for(int k = 1; k <= coin[i].second; k++) {
                if(j - coin[i].first * k < 0) continue;
                dp[j] += dp[j - (coin[i].first * k)];
            }
        }
    }

   
    cout << dp[t];
}
