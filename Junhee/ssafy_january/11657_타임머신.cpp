#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> bus[501];
long long dist[501];

bool bellman_ford() {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < bus[j].size(); k++) {
                int dest = bus[j][k].first;
                int cost = bus[j][k].second;

                if(dist[j] == INF) continue;

                if(dist[dest] > dist[j] + cost) {
                    dist[dest] = dist[j] + cost;
                    if(i == n) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        bus[s].push_back({e, c});
    }

    if(bellman_ford()) {
        cout << -1 << "\n";
        return 0;
    }
    else {
        for(int i = 2; i <= n; i++) {
            if(dist[i] ==  INF) cout << -1 << "\n";
            else cout << dist[i] << "\n";
            //cout << dist[i] << "\n";
        }
    }
    return 0;
}
