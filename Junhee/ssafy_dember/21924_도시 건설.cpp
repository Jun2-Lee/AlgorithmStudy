#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> list;
int parent[100001];
long long total = 0;

int Find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    parent[fb] = fa;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int c, s, e;
        cin >> s >> e >> c;
        total += c;
        list.push_back({c, {s, e}});
    }
    sort(list.begin(), list.end());
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long answer = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        pair<int, pair<int, int>> cur = list[i];
        int cost = cur.first;
        int start = cur.second.first;
        int end = cur.second.second;
        if(Find(start) == Find(end)) continue;
        //cout << cost << " " << start << " " << end << "\n";
        Union(start, end);
        answer += cost;
        cnt++;
    }
    
    if(cnt == n - 1)
        cout << total - answer;
    else
        cout << -1;
    return 0;
}
