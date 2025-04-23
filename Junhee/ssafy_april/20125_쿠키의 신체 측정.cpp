#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int heart_x, heart_y;
int left_arm = 0, right_arm = 0;
int body = 0;
int left_leg = 0, right_leg = 0;
int cookie[1001][1001];

int main() {
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < n; j++) {
            if(temp[j] == '*' && !flag) {
                flag = true;
                heart_x = i + 1;
                heart_y = j;
            }
            if(temp[j] == '*')
                cookie[i][j] = 1;
            else
                cookie[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i < heart_y && cookie[heart_x][i] == 1) left_arm++;
        if(i > heart_y && cookie[heart_x][i] == 1) right_arm++;
    }
    for(int i = heart_x; i < n; i++) {
        if(cookie[i][heart_y] == 1) body++;
    }
    for(int i = 0; i < n; i++) {
        if(cookie[i][heart_y - 1] == 1) left_leg++;
        if(cookie[i][heart_y + 1] == 1) right_leg++;
    }
    cout << heart_x + 1 << " " << heart_y + 1 << "\n";
    cout << left_arm << " " << right_arm << " " << body - 1 << " " << left_leg - 1 << " " << right_leg - 1;
    return 0;
}
