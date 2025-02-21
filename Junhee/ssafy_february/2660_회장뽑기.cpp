#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> list[51];
vector<int> president;
int n;
int num = 999999999;
int cnt = 0;

int bfs(int start) {
    int temp_depth = 0;
    bool visit[51] = {false, };
    queue<pair<int, int>> q;
    q.push({start, 0});
    visit[start] = true;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int node = cur.first;
        int depth = cur.second;
        temp_depth = depth;
        for(int i = 0; i < list[node].size(); i++) {
            int next = list[node][i];
            if(visit[next]) continue;
            visit[next] = true;
            q.push({next, depth + 1});
        }
    }
    return temp_depth;
}

int main() {
    cin >> n;
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        int temp = bfs(i);
        if(temp < num) {
            num = temp;
            cnt = 1;
            president.clear();
            president.push_back(i);
        }
        else if(temp == num) {
            cnt++;
            president.push_back(i);
        }
    }
    cout << num << " " << cnt << "\n";
    for(int i = 0; i < president.size(); i++) {
        cout << president[i] << " ";
    }
    return 0;
}
