#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<int> pin;
vector<double> stick;
double answer = -1;
int main() {
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pin.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        stick.push_back(temp);
    }
    sort(pin.begin(), pin.end());
    sort(stick.begin(), stick.end());
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int left = 0;
            int right = m - 1;
            while(left <= right) {
                int mid = (left + right) / 2;
                double area = (pin[j] - pin[i]) * stick[mid] / 2;
                if(area <= r) {
                    left = mid + 1;
                    answer = (double)max((double)answer, (double)area);
                }
                else {
                    right = mid - 1;
                }
            }
        }
    }
    if(answer == -1) {
        cout << -1;
    }
    else {
        printf("%.1f", answer);
    }
    return 0;
}
