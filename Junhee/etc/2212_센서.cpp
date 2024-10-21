#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> sensor;
vector<int> len;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sensor.push_back(temp);
    }
    sort(sensor.begin(), sensor.end());
    for(int i = 0; i < sensor.size() - 1; i++) {
        len.push_back(sensor[i + 1] - sensor[i]);
    }
    sort(len.begin(), len.end());
    int answer = 0;
    for(int i = 0; i < n - 1 - (k - 1); i++) {
        answer += len[i];
    }
    cout << answer;
    return 0;
}
