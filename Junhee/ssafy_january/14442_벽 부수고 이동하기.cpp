#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int map[1001][1001];
bool visit[1001][1001][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            map[i][j] = temp[j] - '0';
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 0}});
    visit[0][0][0] = true;
    int answer = -1;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int depth = q.front().second.first;
        int wall = q.front().second.second;
        q.pop();
        if(x == n - 1 && y == m - 1) {
            answer = depth + 1;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(visit[nx][ny][wall]) continue;
                if(map[nx][ny] == 1 && wall < k) {
                    visit[nx][ny][wall + 1] = true;
                    q.push({{nx, ny}, {depth + 1, wall + 1}});
                }
                else if(map[nx][ny] == 0) {
                    visit[nx][ny][wall] = true;
                    q.push({{nx, ny}, {depth + 1, wall}});
                }
            }
        }
    }
    cout << answer;
    return 0;
}
