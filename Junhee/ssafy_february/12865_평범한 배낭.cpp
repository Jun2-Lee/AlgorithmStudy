#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int dp[100001];
vector<pair<int, int>> item;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        item.push_back({w, v});
    }
    for(int i = 0; i < n; i++) {
        int w = item[i].first;
        int v = item[i].second;
        for(int j = k; j - w >= 0; j--) {
            dp[j] = max(dp[j - w] + v, dp[j]);
        }
    }
    cout << dp[k];
    return 0;
}
