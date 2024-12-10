#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pizza;
vector<int> oven;
int d, n;

int main() {
    cin >> d >> n;
    for(int i = 0; i < d; i++) {
        int temp;
        cin >> temp;
        oven.push_back(temp);
    }
    for(int i = 1; i < d; i++) {
        if(oven[i] > oven[i - 1])
            oven[i] = oven[i - 1];
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pizza.push_back(temp);
    }
    if(pizza.size() > oven.size()) {
        cout << 0;
        return 0;
    }
    int idx = 0;
    int answer = 0;
    bool flag = false;
    for(int i = d - 1; i >= 0; i--) {
        if(pizza[idx] <= oven[i]) {
            idx++;
            answer = i;
            //cout << answer << "\n";
        }
        if(idx >= n) {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << answer + 1;
    else
        cout << 0;
    return 0;
}
