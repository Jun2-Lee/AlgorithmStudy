#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int node[100001];
long long dist[100001];
vector<pair<int,int>> list[100001];

void dijkstra() {
    priority_queue<pair<long long,int>> pq;
    for(int i = 0; i < N; i++) {
        dist[i] = 1000000000001;
    }
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        long long cost = -1 * pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;
        for(int i = 0; i < list[cur].size(); i++) {
            int next = list[cur][i].first;
            if(next != N - 1 && node[next] == 1) continue;
            long long t_cost = cost + list[cur][i].second;

            if(t_cost < dist[list[cur][i].first]) {
                dist[list[cur][i].first] = t_cost;
                pq.push({-t_cost, list[cur][i].first});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> node[i];
    }
    for(int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        list[s].push_back({e, c});
        list[e].push_back({s, c});
    }
    dijkstra();
    if(dist[N - 1] != 1000000000001)
        cout << dist[N - 1];
    else
        cout << -1;
    return 0;
}
