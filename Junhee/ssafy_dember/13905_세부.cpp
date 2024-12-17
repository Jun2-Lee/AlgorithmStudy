#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, s, e;
vector<pair<int, int>> list[100001];

bool bfs(int cost) {
    queue<int> q;
    bool visit[100001] = {false, };
    q.push(s);
    visit[s] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == e) return true;
        for(int i = 0; i < list[cur].size(); i++) {
            pair<int, int> next = list[cur][i];
            if(!visit[next.first] && next.second >= cost) {
                visit[next.first] = true;
                q.push(next.first);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> s >> e;
    for(int i = 0; i < m; i++) {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        list[start].push_back({dest, cost});
        list[dest].push_back({start, cost});
    }
    int start = 0;
    int end = 1000001;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(bfs(mid)) start = mid + 1;
        else end = mid - 1;
    }
    //cout << start << " " << end;
    if(end >= 0) cout << end;
    else cout << 0;
    return 0;
}
