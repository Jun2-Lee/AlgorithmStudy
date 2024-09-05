#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, q, m;
vector<int> car_list;


void calc(int m) {
    int size = car_list.size();
    int idx = lower_bound(car_list.begin(), car_list.end(), m) - car_list.begin();
    if(m != car_list[idx]) cout << 0 << "\n";
    else {
        cout << idx * (size  - idx - 1) << "\n";
    }
}

int main(int argc, char** argv)
{
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        car_list.push_back(temp);
    }
    sort(car_list.begin(), car_list.end());
    for(int i = 0; i < q; i++) {
        cin >> m;
        calc(m);
    }
   return 0;
}
