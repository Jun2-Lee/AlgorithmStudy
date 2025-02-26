#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long dp[31];
int answer = 0;

void katalan(int num) {
    long long sum = 0;
    for(int i = 0; i < num; i++) {
        long long f = dp[i];
        long long b = dp[num - 1 - i];
        sum += f * b;
    }
    dp[num] = sum;
}

int main() {
    int num;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 30; i++) {
        katalan(i);
    }
    while(true) {
        cin >> num;
        if(num == 0) break;
        cout << dp[num] << "\n";
    }

    return 0;
}
