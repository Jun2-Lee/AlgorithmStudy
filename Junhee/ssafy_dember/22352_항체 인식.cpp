#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int map[30][30];
int map2[30][30];
vector<pair<int, int>> dna;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs() {
    queue<pair<int, int>> q;
    q.push(dna[0]);
    int num = map2[dna[0].first][dna[0].second];
    int visit = map[dna[0].first][dna[0].second];
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        map[cur.first][cur.second] = num;
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == visit) {
                q.push({nx, ny});
            } 
        }
    }
}

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] != map2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map2[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] != map2[i][j]) {
                dna.push_back({i, j});
            }
        }
    }
    if(dna.size() == 0) {
        cout << "YES";
        return 0;
    }
    bfs();
    if(check()) cout << "YES";
    else cout << "NO";
    return 0;
}
