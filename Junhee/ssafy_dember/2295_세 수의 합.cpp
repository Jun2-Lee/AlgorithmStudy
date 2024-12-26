#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> sum;
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum.push_back(v[i] + v[j]);
        }
    }
    sort(sum.begin(), sum.end());
    int answer = -1;
    for(int i = 0; i < v.size(); i++) {
        
        for(int j = i; j < v.size(); j++) {
            int diff = v[j] - v[i];
            //cout << "diff = " << diff << " ";
            int start = 0, end = sum.size();
            while(start <= end) {
                int mid = (start + end) / 2;
                if(sum[mid] > diff) {
                    end = mid - 1;
                }
                else if(sum[mid] < diff) {
                    start = mid + 1;
                }
                else {
                    answer = max(answer, v[j]);
                    //cout << v[j] << " ";
                    break;
                }
            }
            //cout << endl;
        }
    }
    cout << answer;
    return 0;
}
