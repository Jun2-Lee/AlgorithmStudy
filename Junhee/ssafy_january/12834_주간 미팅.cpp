#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, v, e, a, b;
vector<int> house;
vector<pair<int, int>> list[1001];
int dist_a[1001];
int dist_b[1001];

void dijkstra_a(int start) {
    dist_a[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist_a[cur] < dist) continue;

        for(int i = 0; i < list[cur].size(); i++) {
            int cost = dist + list[cur][i].second;
            if(cost < dist_a[list[cur][i].first]) {
                dist_a[list[cur][i].first] = cost;
                pq.push({-cost, list[cur][i].first});
            }
        }
    }
}

void dijkstra_b(int start) {
    dist_b[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist_b[cur] < dist) continue;

        for(int i = 0; i < list[cur].size(); i++) {
            int cost = dist + list[cur][i].second;
            if(cost < dist_b[list[cur][i].first]) {
                dist_b[list[cur][i].first] = cost;
                pq.push({-cost, list[cur][i].first});
            }
        }
    }
}

int main() {
    cin >> n >> v >> e >> a >> b;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }
    for(int i = 0; i < e; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        list[s].push_back({d, c});
        list[d].push_back({s, c});
    }
    for(int i = 1; i <= v; i++) {
        dist_a[i] = 987654321;
        dist_b[i] = 987654321;
    }
    dijkstra_a(a);
    dijkstra_b(b);
    // for(int i = 1; i <= v; i++) {
    //     cout << dist_a[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= v; i++) {
    //     cout << dist_b[i] << " ";
    // }
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(dist_a[house[i]] == 987654321) answer += -1;
        else answer += dist_a[house[i]];
        if(dist_b[house[i]] == 987654321) answer += -1;
        else answer += dist_b[house[i]];
    }
    cout << answer;
    return 0;
}
