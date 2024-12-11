#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int people[200001];
vector<int> list[200001];
vector<int> first_rumor;

bool check(int node) {
    int cnt = 0;
    for(int i = 0; i < list[node].size(); i++) {
        if(people[list[node][i]] > -1)
            cnt++;
    }
    //cout << cnt << endl;
    if(cnt >= (list[node].size() + 1) / 2) return true;
    return false;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        people[i] = -1;
        while(true) {
            int temp;
            cin >> temp;
            if(temp == 0) break;
            list[i].push_back(temp);
        }
    }
    queue<int> q;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        first_rumor.push_back(temp);
        people[temp] = 0;
        q.push(temp);
    }
    queue<int> temp_q;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int time = people[cur];
        for(int i = 0; i < list[cur].size(); i++) {
            if(people[list[cur][i]] != -1) continue;
            if(check(list[cur][i])) {
                //cout << 1 << endl;
                temp_q.push(list[cur][i]);
            }
        }
        //cout << endl;
        if(q.empty()) {
            while(!temp_q.empty()) {
                int next = temp_q.front();
                temp_q.pop();
                people[next] = time + 1;
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << people[i] << " ";
    }
    return 0;
}










