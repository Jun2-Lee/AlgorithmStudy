#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r;
int map[51][51];
bool visit[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y) {
    bool temp_visit[51][51];
    memset(temp_visit, false, sizeof(temp_visit));
    int cnt = 0, sum = 0;
    queue<pair<int, int>> q;
    visit[x][y] = true;
    temp_visit[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        cnt++;
        sum += map[cx][cy];
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny]) {
                int diff = abs(map[cx][cy] - map[nx][ny]);
                if(l <= diff && diff <= r) {
                    visit[nx][ny] = true;
                    temp_visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(cnt > 1) {
        int value = sum / cnt;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(temp_visit[i][j]) map[i][j] = value;
            }
        }
    }
}


int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    while(true) {
        memset(visit, false, sizeof(visit));
        int flag = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visit[i][j]) {
                    bfs(i, j);
                    flag++;
                }
            }
        }
        cnt++;
        if(flag >= n * n) break;
    }
    
    cout << cnt - 1;
    return 0;
}
