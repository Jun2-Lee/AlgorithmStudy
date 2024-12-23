#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int start[3];
vector<pair<int, int>> list[100001];
int dist[3][100001];
int answer = 0;
int max_dist = -1;

void dijkstra(int num) {
    fill(dist[num], dist[num] + 100001, 987654321);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start[num]});
    dist[num][start[num]] = 0;
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[num][cur] < cost) continue;
        for(int i = 0; i < list[cur].size(); i++) {
            if(cost + list[cur][i].second < dist[num][list[cur][i].first]) {
                dist[num][list[cur][i].first] = cost + list[cur][i].second;
                pq.push({-dist[num][list[cur][i].first], list[cur][i].first});
            }
        }
    }
}

int main() {
    cin >> n >> start[0] >> start[1] >> start[2] >> m;
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        list[s].push_back({e, c});
        list[e].push_back({s, c});
    }
    for(int i = 0; i < 3; i++) {
        dijkstra(i);
    }
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++) {
        if(start[0] == i || start[1] == i || start[2] == i) continue;
        int temp = 987654321;
        for(int j = 0; j < 3; j++) {
            temp = min(dist[j][i], temp);
        }
        if(max_dist < temp) {
            max_dist = temp;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}
