#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> coding;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        coding.push_back(temp);
    }
    sort(coding.begin(), coding.end());
    long long answer = 0;
    for(int i  = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int num1 = coding[i];
            int num2 = coding[j];
            int sum = num1 + num2;
            auto lower = lower_bound(coding.begin() + j + 1, coding.end(), -1 * sum) - coding.begin();
            auto upper = upper_bound(coding.begin() + j + 1, coding.end(), -1 * sum) - coding.begin();
            answer += upper - lower;
            // cout << "upper = " << upper << endl;
            // cout << "lower = " << lower << endl;

        }
    }
    cout << answer;
    return 0;
}
