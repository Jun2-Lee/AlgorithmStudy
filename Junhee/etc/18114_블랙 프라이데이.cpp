#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> list;

int main() {
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    sort(list.begin(), list.end());
    bool flag = false;
    
    for(int i = 0; i < N; i++) {
        if(list[i] == C) {
            flag = true;
            break;
        }
    }
    
    if(!flag) {
        for(int i = 0; i < N; i++) {
            int left = i + 1;
            while(left < N) {
                int sum = list[i] + list[left];
                if(sum == C) {
                    flag = true;
                    break;
                } else if(sum < C) {
                    left++;
                } else {
                    break;
                }
            }
            if(flag) break;
        }
    }
    
    if(!flag) {
        for(int i = 0; i < N; i++) {
            int left = i + 1;
            int right = N - 1;
            
            while(left < right) {
                int sum = list[i] + list[left] + list[right];
                if(sum == C) {
                    flag = true;
                    break;
                } else if(sum < C) {
                    left++;
                } else {
                    right--;
                }
            }
            if(flag) break;
        }
    }
    
    if(flag) cout << 1;
    else cout << 0;
    
    return 0;
}
