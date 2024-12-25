#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
int house[1000001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << n << "\n" << 1 << " ";
    int cur = 1;
    if(n % 3 == 2) {
        cur++;
        cout << cur << " ";
    }
    while(true) {
        cur += 2;
        cout << cur << " ";
        cur -= 1;
        cout << cur << " ";
        cur += 2;
        if(cur % n == 1 && n % 3 == 0)
            break;
        cout << cur << " ";
        if(cur == n && n % 3 == 1) {
            break;
        }
        if(cur == n && n % 3 == 2) {
            break;
        }
    }
    cout << 1;
    return 0;
}
