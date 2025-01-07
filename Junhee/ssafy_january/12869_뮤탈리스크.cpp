#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct temp {
    int f, s, t;
};

int n;
int moving[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};
int scv[3];
int hp[61][61][61];

void bfs() {
    bool visit[61][61][61] = {false, };
    queue<temp> q;
    visit[scv[0]][scv[1]][scv[2]] = true;
    q.push({scv[0], scv[1], scv[2]});

    while(!q.empty()) {
        temp cur = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            int nf = max(0, cur.f - moving[i][0]);
            int ns = max(0, cur.s - moving[i][1]);
            int nt = max(0, cur.t - moving[i][2]);
            if(visit[nf][ns][nt]) continue;
            visit[nf][ns][nt] = true;
            hp[nf][ns][nt] = hp[cur.f][cur.s][cur.t] + 1;
            q.push({nf, ns, nt});
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        scv[i] = temp;
    }
    bfs();
    
    cout << hp[0][0][0];
}
