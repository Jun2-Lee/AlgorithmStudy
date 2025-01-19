#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct stone {
    int a, b, c;
};

bool visit[1500][1500];
int a, b, c;
int main() {
    cin >> a >> b >> c;
    queue<stone> q;
    q.push({a, b, c});
    bool flag = false;
    while(!q.empty()) {
        stone cur = q.front();
        q.pop();
        if(cur.a == cur.b && cur.b == cur.c) {
            flag = true;
            break;
        }
        vector<int> c_stone;
        c_stone.push_back(cur.a);
        c_stone.push_back(cur.b);
        c_stone.push_back(cur.c);
        sort(c_stone.begin(), c_stone.end());
        if(c_stone[0] != c_stone[1]) {
            int na = c_stone[0] * 2;
            int nb = c_stone[1] - c_stone[0];
            if(!visit[na][nb]) {
                visit[na][nb] = true;
                q.push({na, nb, c_stone[2]});
            }
        }
        if(c_stone[0] != c_stone[2]) {
            int na = c_stone[0] * 2;
            int nb = c_stone[2] - c_stone[0];
            if(!visit[na][nb]) {
                visit[na][nb] = true;
                q.push({na, nb, c_stone[1]});
            }
        }
        if(c_stone[2] != c_stone[1]) {
            int na = c_stone[1] * 2;
            int nb = c_stone[2] - c_stone[1];
            if(!visit[na][nb]) {
                visit[na][nb] = true;
                q.push({na, nb, c_stone[0]});
            }
        }
    }
    if(flag) cout << 1;
    else cout << 0;
    return 0;
}
