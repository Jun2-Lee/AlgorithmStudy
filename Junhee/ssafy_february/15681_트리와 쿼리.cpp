#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, r, q;
vector<int> list[100001];
bool visit[100001];
int dp[100001];

void dfs(int cur, int from) {
    visit[cur] = true;
    for(int i = 0; i < list[cur].size(); i++) {
        if(!visit[list[cur][i]]) {
            dfs(list[cur][i], cur);
        }
    }
    if(from != -1) {
        dp[from] += dp[cur];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> q;
    for(int i = 0; i <= n; i++) {
        dp[i] = 1;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    dfs(r, -1);
    for(int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        cout << dp[temp] << "\n";
    }
    return 0;
}
