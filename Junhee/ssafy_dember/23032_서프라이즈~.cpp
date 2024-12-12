#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int w[2001];
int prefix[2001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        w[i] = temp;
        prefix[i] = prefix[i - 1] + temp;
    }
    int min = 20000000;
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        int mid = i;
        int left_start = 0;
        int right_end = n;
        while(left_start < mid && right_end > mid) {
            int left = prefix[mid] - prefix[left_start];
            int right = prefix[right_end] - prefix[mid];
            //cout << mid << " left_start = " << left_start << " right_start = " << right_end << endl;
            //cout << "left = " << left << " right = " << right << endl;
            if(abs(left - right) < min) {
                min = abs(left - right);
                answer = left + right;
            }
            else if(abs(left - right) == min && left + right > answer) {
                answer = left + right;
            }
            // cout << "min = " << min << endl;
            // cout << "answer = " << answer << endl;
            if(left > right) {
                //cout << 1 << endl;
                left_start++;
            }
            else if(right > left) {
                //cout << 2 << endl;
                right_end--;
            }
            else {
                break;
            }
        }
        //cout << "===========================\n"; 
    }
    cout << answer;
    return 0;
}
