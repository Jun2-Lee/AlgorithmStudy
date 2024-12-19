#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[50][50];
int temp_map[50][50];
int cnt = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int answer = 987654321;
vector<pair<int, int>> virus;
bool choose_virus[10] = {false, };
bool ans_flag = false;

bool check() {
    bool flag = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(temp_map[i][j] == 0) flag = false;
        }
    }
    return flag;
}

int bfs() {
    int temp_answer = -1;
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(temp_map[i][j] == 2) q.push({{i, j}, 0});
        }
    }
    while(!q.empty()) {
        pair<int, int> cur = q.front().first;
        int time = q.front().second;
        temp_answer = max(temp_answer, time);
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < n && temp_map[nx][ny] == 0) {
                temp_map[nx][ny] = 3;
                q.push({{nx, ny}, time + 1});
            }
        }
    }
    return temp_answer;
}

void choose(int cur, int count) {
    if(count == m) {
        // 다 골랐을 때
        copy(&map[0][0], &map[0][0]+2500, &temp_map[0][0]);
        // for(int i = 0; i < cnt; i++) {
        //     cout << virus[i].first << " " << virus[i].second;
        //     cout << endl;
        // }
        // cout << endl;
        for(int i = 0; i < cnt; i++) {
            if(choose_virus[i]) {
                pair<int, int> v = virus[i];
                //pair<int, int> v = {0, 0};
                temp_map[v.first][v.second] = 2;
            }
        }
        int t_ans = bfs();
        if(check()) {
            answer = min(t_ans, answer);
            ans_flag = true;
        }
    }
    for(int i = cur + 1; i < cnt; i++) {
        choose_virus[i] = true;
        choose(i, count + 1);
        choose_virus[i] = false;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            map[i][j] = temp;
            if(temp == 2) { 
                cnt++;
                map[i][j] = 0;
                virus.push_back({i, j});
            }
        
        }
    }
    memset(choose_virus, false, sizeof(choose_virus));
    choose(-1, 0);
    // copy(&map[0][0], &map[0][0]+2500, &temp_map[0][0]);
    // bfs();
    // if(check()) cout << answer;
    // else cout << -1;
    if(ans_flag) cout << answer;
    else cout << -1;
    return 0;
}
