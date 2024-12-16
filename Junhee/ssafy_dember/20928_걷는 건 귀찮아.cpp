#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cycle;
vector<int> length;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cycle.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        length.push_back(temp);
    }
    int idx = 0;
    int answer = 0;
    bool is_answer = false;
    while(idx < n) {
        bool flag = false;
        int temp = idx + 1;
        int temp_max = -1;
        int cur = cycle[idx];
        int max_len = cycle[idx] + length[idx];
        if(cycle[idx] <= m && m <= cycle[idx] + length[idx]) {
            cout << answer;
            is_answer = true;
            break;
        }
        while (cur <= cycle[temp] && cycle[temp] <= max_len) {
            int temp_len = cycle[temp] + length[temp];
            if(temp_max < temp_len) {
                idx = temp;
                temp_max = temp_len;
                flag = true;
            }
            temp++;
        }
        if(flag) answer++;
        if(!flag && !(cycle[idx] <= m && m <= cycle[idx] + length[idx])) {
            break;
        }
    }
    if(!is_answer) cout << -1;
    return 0;
}



