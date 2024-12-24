#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> date;
int year[367];
int answer = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        date.push_back({s, e});
        for(int i = s; i <= e; i++) {
            year[i]++;
        }
    }
    int h = 0;
    int l = 0;
    for(int i = 0; i < 367; i++) {
        if(year[i] == 0) {
            answer += h * l;
            h = 0;
            l = 0;
        }
        else {
            h = max(h, year[i]);
            l++;
        }
    }
    cout << answer;
    return 0;
}
