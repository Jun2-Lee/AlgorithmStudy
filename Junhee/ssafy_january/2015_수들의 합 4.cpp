#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;
long long number;

int main() {
    cin >> n >> k;
    long long now = 0;
    unordered_map<int, long long> map;
    map[now]++;
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        cin >> number;
        now += number;
        answer += map[now - k];
        map[now]++;
    }
    cout << answer;
    return 0;
}
