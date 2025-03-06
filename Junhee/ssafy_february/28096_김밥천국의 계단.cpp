#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
int n, k;
int stair[1000001];

int main() {
    cin >> n >> k;
    int cnt = 1;
    q.push(2);
    stair[1] = 1;
    stair[2] = 2;
    while(!q.empty()) {
        int cur = q.front();        
        q.pop();
        if(cur + 1 <= 1000000 && stair[cur + 1] == 0) {
            stair[cur + 1] = stair[cur] + 1;
            q.push(cur + 1);
        }
        if(cur + cur / 2 <= 1000000 && stair[cur + cur / 2] == 0) {
            stair[cur + cur / 2] = stair[cur] + 1;
            q.push(cur + cur / 2);
        }
    }
    if(stair[n] <= k) cout << "minigimbob";
    else cout << "water";
    return 0;
}
