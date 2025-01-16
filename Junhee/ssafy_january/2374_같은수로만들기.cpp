#include <iostream>
#include <vector>
using namespace std;

long long A[1000001];
vector<long long> v;

    int n;
    long long output = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (v.empty()) {
            v.push_back(A[i]);
        } else {
            while (v.back() < A[i]) {
                long long del = v.back();
                v.pop_back();
                if (v.empty() || v.back() > A[i]) {
                    output += (A[i] - del);
                    break;
                } else {
                    output += (v.back() - del);
                }
            }
            v.push_back(A[i]);
        }
    }
    if (v.size() > 1) {
        output += (v.front() - v.back());
    }
    cout << output << "\n";
    return 0;
}
