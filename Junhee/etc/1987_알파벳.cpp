#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int r, c;
int map[20][20];
int answer = -1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[26];

void dfs(int x, int y, int depth) {
    answer = max(answer, depth);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            if (!visit[map[nx][ny]]) {
                visit[map[nx][ny]] = true;
                dfs(nx, ny, depth + 1);
                visit[map[nx][ny]] = false;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < c; j++) {
            map[i][j] = temp[j] - 'A';
        }
    }
    visit[map[0][0]] = true;
    dfs(0,0,1);
    cout << answer;
    return 0;
}
