#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, l, r, x;
vector<int> problem;
int answer = 0;

void dfs(int cur, int cnt, int total, int min_level, int max_level) {
    if(cnt >= 2) {
        if(max_level - min_level >= x && l <= total && total <= r) {
            answer++;
        }
    }
    for(int i = cur + 1; i < n; i++) {
        dfs(i, cnt + 1, total + problem[i], min(min_level, problem[i]), max(max_level, problem[i]));
    }
}


int main() {
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        problem.push_back(temp);
    }
    sort(problem.begin(), problem.end());
    dfs(-1, 0, 0, INT_MAX, INT_MIN);
    cout << answer;
    return 0;
}
