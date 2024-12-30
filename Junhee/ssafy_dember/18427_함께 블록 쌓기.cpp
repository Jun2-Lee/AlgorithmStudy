#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m, h;
vector<int> block[51];
int dp[51][1001];

int main() {
    cin >> n >> m >> h;
    string temp;
    getline(cin, temp);
    for(int i = 1; i <= n; i++) {
        string input;
        getline(cin, input);
        //cout << input << "\n";
        int temp = 0;
        for(int j = 0; j < input.size(); j++) {
            if(input[j] == ' ') {
                block[i].push_back(temp);
                temp = 0;
            }
            else {
                temp *= 10;
                temp += input[j] - '0';
            }
        }
        if(temp != 0) block[i].push_back(temp);
    }
    // for(int i = 1; i <= n; i++) {
    //     //cout << "i = " << i << " ";
    //     for(int j = 0; j < block[i].size(); j++) {
    //         cout << block[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= h; j++) {
            for(int k = 0; k < block[i].size(); k++) {
                if(block[i][k] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - block[i][k]]) % 10007;
                }
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n][h] << "\n";
    return 0;
}
