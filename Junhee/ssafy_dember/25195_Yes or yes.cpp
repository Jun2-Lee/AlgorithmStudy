#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> list[100001];
bool fan[100001];
bool answer = false;
void dfs(int cur) {
    if(list[cur].size() == 0) {
        if(!fan[cur]) {
            answer = true;
            return;
        }
    }
    if(fan[cur]) {
        return;
    }
    for(int i = 0; i < list[cur].size(); i++) {
        int next = list[cur][i];
        dfs(next);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        list[s].push_back(e);
    }
    cin >> s;
    for(int i = 0; i < s; i++) {
        int f;
        cin >> f;
        fan[f] = true;
    }
    dfs(1);
    if(answer) cout << "yes";
    else cout << "Yes";
    return 0;
}
