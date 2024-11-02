#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int ans_cnt = 0;
int ans_time = 99999999;


void bfs(int start) {
    bool visit[100001] = {false, };
    queue<pair<int, int>> q;
    q.push({start, 0});
    visit[start] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        visit[cur] = true;
        //cout << cur << " " << time << "\n";
        if(cur == K && ans_time > time) {
            ans_time = time;
            ans_cnt = 1;
        }
        else if(cur == K && ans_time == time) {
            ans_cnt++;
        }
        if(time > ans_time) break;
        int next = cur + 1;
        if(0 <= next && next < 100001) {
            if(!visit[next]){
                q.push({next, time + 1});
            }
        }
        next = cur - 1;
        if(0 <= next && next < 100001) {
            if(!visit[next]){
                q.push({next, time + 1});
            }
        }
        next = cur * 2;
        if(0 <= next && next < 100001) {
            if(!visit[next]){
                q.push({next, time + 1});
            }
        }
    }
}


int main() {
    cin >> N >> K;
    bfs(N);
    cout << ans_time << "\n" << ans_cnt;
    return 0;
}
