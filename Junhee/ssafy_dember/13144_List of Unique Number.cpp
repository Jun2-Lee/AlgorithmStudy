#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> number;
bool visit[100001];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        number.push_back(temp);
    }

    long long start = 0;
    long long end = 0;
    long long answer = 0;

    while (start < n) {
        if (end < n && !visit[number[end]]) {
            visit[number[end]] = true;
            end++;
        } else {
            answer += (end - start);
            visit[number[start]] = false;
            start++;
        }
    }

    cout << answer;

    return 0;
}
