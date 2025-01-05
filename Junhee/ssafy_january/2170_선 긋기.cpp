#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        line.push_back({x, y});
    }
    sort(line.begin(), line.end());
    int start = line[0].first;
    int end = line[0].second;
    long long answer = 0;
    for(int i = 1; i < n; i++) {
        int next_start = line[i].first;
        int next_end = line[i].second;
        if(next_start <= end && next_end > end) {
            end = next_end;
        }
        else if(next_start > end) {
            answer += end - start;
            start = next_start;
            end = next_end;
        }
    }
    answer += end - start;
    cout << answer;
    return 0;
}
