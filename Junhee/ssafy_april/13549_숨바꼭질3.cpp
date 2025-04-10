#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int load[100001];
int visit[100001];

void bfs() {
    queue<int> q;
    q.push(n);
    visit[n] = 0;
    while(!q.empty()) {
        int cur = q.front();
        if(cur == k) break;
        q.pop();
        int depth = visit[cur];
        if(cur * 2 <= 100000 && visit[cur * 2] == -1){
            visit[cur * 2] = depth;
            q.push(cur * 2);
        }
        if(cur - 1 >= 0 && visit[cur - 1] == -1){
            visit[cur - 1] = depth + 1;
            q.push(cur - 1);
        }
        if(cur + 1 <= 100000 && visit[cur + 1] == -1){
            visit[cur + 1] = depth + 1;
            q.push(cur + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < 100001; i++) {
        visit[i] = -1;
    }
    bfs();
    cout << visit[k];
    return 0;
}
