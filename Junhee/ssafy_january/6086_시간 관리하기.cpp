#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> work;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        work.push_back({t, s});
    }
    sort(work.begin(), work.end(), compare);
    
    int time = 0;
    int answer = 987654321;
    for(int i = 0; i < n; i++) {
        int t, s;
        t = work[i].first;
        s = work[i].second;
        time += t;
        answer = min(answer, s - time);
        
    }
    if(answer < 0) cout << -1;
    else cout << answer;
    return 0;
}
