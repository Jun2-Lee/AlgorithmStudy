#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    int start = 0, end = 0;
    int diff = 0;
    int answer = 2000000001;
    while(start != n - 1) {
        diff = num[end] - num[start];
        if(diff >= m) {
            answer = min(answer, diff);
            start++;
        }
        else {
            end++;
        }
        if(end == n && diff < m) break;
    }
    cout << answer;
    return 0;
}
