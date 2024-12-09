#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int map[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

bool bfs(int h) {
    queue<pair<int, int>> q;
    bool visit[1001][1001] = {false ,};
    
    q.push({0, 0});
    visit[0][0] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        if (x == n - 1 && y == n - 1) return true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny]) {
                if (abs(map[x][y] - map[nx][ny]) <= h) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int start = 0, end = 1000000000, result = end;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (bfs(mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    cout << result << endl;
    return 0;
}
