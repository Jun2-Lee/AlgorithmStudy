#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        vector<pair<int,int>> list[10001];
        int n, d, com;
        cin >> n >> d >> com;
        for(int i = 0; i < d; i++) {
            int s, e, c;
            cin >> s >> e >> c;
            list[e].push_back({s, c});
        }
        priority_queue<pair<int, int>> pq;
        int dist[10001];
        for(int i = 1; i < n + 1; i++) {
            dist[i] = 10000001;
        }
        dist[com] = 0;

        pq.push({0, com});
        while(!pq.empty()) {
            int cost = -1 * pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(dist[cur] < cost) {
                continue;
            }
            for(int i = 0; i < list[cur].size(); i++) {
                int next = list[cur][i].first;
                int ncost = list[cur][i].second + cost;
                if(dist[next] > ncost) {
                    dist[next] = ncost;
                    pq.push({-1 * ncost, next});
                }
            }
        }
        int cnt = 0;
        int time = 0;
        for(int i = 1; i < n + 1; i++) {
            if(dist[i] != 10000001) {
                cnt++;
                time = max(time, dist[i]);
            }
        }
        cout << cnt << " " << time << "\n"; 
    }
    return 0;
}
