#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<pair<int,int>> ladder;
int visit[101];

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        int depth = visit[cur];
        q.pop();
        for(int i = 1; i <= 6; i++) {
            int next = cur + i;
            if(next > 100) continue;
            for(int j = 0; j < ladder.size(); j++) {
                if(ladder[j].first == next) {
                    next = ladder[j].second;
                    break;
                }
            }
            if(visit[next] != 0) continue;
            visit[next] = depth + 1;
            q.push(next);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) {
        int s, e;
        cin >> s >> e;
        ladder.push_back({s, e});
    }
    bfs();
    cout << visit[100];
    return 0;
}
