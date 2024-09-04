#include<iostream>
#include<vector>

using namespace std;

int map[4][4];
vector<pair<int, int>> n_list;
vector<int> answer;
int ex, ey;
bool visit[4][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
vector<vector<int>> ans_list;
vector<int> temp;

void dfs(int x, int y) {
    if(x == ex && y == ey) {
        ans_list.push_back(temp);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(visit[nx][ny]) continue;
            if(map[nx][ny] == 1) continue;
            visit[nx][ny] = true;
            temp.push_back(nx * n + ny);
            dfs(nx, ny);
            temp.pop_back();
            visit[nx][ny] = false;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n >> m;   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        n_list.push_back({x - 1, y - 1});
        answer.push_back((x - 1) * n + y - 1);
    }
    ex = n_list[n_list.size() -1].first;
    ey = n_list[n_list.size() -1].second;
    int cnt = 0;
    temp.push_back(n_list[0].first*n + n_list[0].second);
    visit[n_list[0].first][n_list[0].second] = true;
    dfs(n_list[0].first, n_list[0].second);
    for(int i = 0; i < ans_list.size(); i++) {
        int idx = 0;
        for(int j = 0; j < ans_list[i].size(); j++) {
            if(ans_list[i][j] == answer[idx]) {
                idx++;
            }
        }
        if(idx == answer.size())
            cnt++;
    }
    cout << cnt;
    return 0;
}
