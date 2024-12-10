#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> machine;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        pq.push(0);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        machine.push_back(temp);
    }
    sort(machine.begin(), machine.end(), greater<>());
    for(int i = 0; i < n; i++) {
        int now = pq.top();
        pq.pop();
        now += machine[i];
        pq.push(now);
    }
    int answer = 0;
    while(!pq.empty()) {
        answer = pq.top();
        pq.pop();
    }
    cout << answer;
    return 0;
}
