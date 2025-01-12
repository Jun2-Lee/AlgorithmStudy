#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> exam;
int sum = 0;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        exam.push_back(temp);
        sum += temp;
    }

    int start = 0, end = sum;
    while(start <= end) {
        int mid = (start + end) / 2;
        int t_sum = 0, group = 0;
        for(int i = 0; i < n; i++) {
            t_sum += exam[i];
            if(t_sum > mid) {
                t_sum = 0;
                group++;
            }
        }

        if(group >= k) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    //cout << start << " "  << end;
    cout << start;
    return 0;
}
