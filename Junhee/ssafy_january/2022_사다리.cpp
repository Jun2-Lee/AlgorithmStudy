#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double x, y, c;
int main() {
    cin >> x >> y >> c;
    double start = 0;
    double end = min(x, y);
    double answer;
    while(true) {
        double mid = (start + end) / 2;
        double h1 = sqrt((y * y) - (mid * mid));
        double h2 = sqrt((x * x) - (mid * mid));
        double tc = (h1 * h2) / (h1 + h2);
        //cout << tc << " " << mid << "\n";
        if(abs(tc - c) < 0.00001) {
            answer = mid;
            break;
        }
        else if(tc > c) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    cout << answer;
    
}
