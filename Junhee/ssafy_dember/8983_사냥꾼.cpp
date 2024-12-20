#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int m, n, l, p[100000], ans;
pair<int,int> ani[100000];

int main(){
    cin >> m >> n >> l;
    for(int i=0;i<m;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> ani[i].first >> ani[i].second;
    sort(p, p + m);
    sort(ani, ani + n);
    int j = 0;
    for(int i = 0; i < m; i++){
        for(; j < n; j++){
            if(i < m - 1 && (abs(ani[j].first-p[i]) > abs(ani[j].first-p[i+1]))) break;
            if((abs(ani[j].first-p[i]) + ani[j].second) <= l) ans++;
        }
    }
    cout << ans;
}
