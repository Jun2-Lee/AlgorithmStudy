#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> solution;
int answer_s, answer_e;
int diff = INT_MAX;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        solution.push_back(temp);
    }
    sort(solution.begin(), solution.end());
    int left = 0;
    int right = n - 1;
    while(true) {
        if(left >= right) break;
        int t_diff = solution[left] + solution[right];
        if(diff > abs(t_diff)) {
            diff = abs(t_diff);
            answer_s = solution[left];
            answer_e = solution[right];
        }
        if(t_diff < 0) {
            left++;
        }
        else if(t_diff > 0) {
            right--;
        }
        else {
            cout << answer_s << " " << answer_e;
            return 0;
        }
    }
    cout << answer_s << " " << answer_e;
    return 0;
}
