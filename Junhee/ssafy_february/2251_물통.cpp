#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visit[201][201];
int from[6] = { 0, 0, 1, 1, 2, 2 };
int to[6] = { 1, 2, 0, 2, 0, 1 };
int result[201];
int capacity[3];
queue<pair<int, int>> q;

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i];
    }

    result[capacity[2]] = 1;
    visit[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        int c = capacity[2] - a - b;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int temp[3];
            temp[0] = a;
            temp[1] = b;
            temp[2] = c;
            temp[to[i]] += temp[from[i]];
            temp[from[i]] = 0;
            if (temp[to[i]] > capacity[to[i]]) {
                temp[from[i]] = temp[to[i]] - capacity[to[i]];
                temp[to[i]] = capacity[to[i]];
            }
            if (!visit[temp[0]][temp[1]]) {
                visit[temp[0]][temp[1]] = 1;
                q.push({ temp[0], temp[1] });
                if (temp[0] == 0) {
                    result[temp[2]] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= capacity[2]; i++) {
        if (result[i]) cout << i << " ";
    }

    return 0;
}
