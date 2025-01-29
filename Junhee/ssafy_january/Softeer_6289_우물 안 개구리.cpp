#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weight;
vector<int> friends[100001];
int n, m;

int main(int argc, char** argv)
{
    cin >> n >> m;
    weight.push_back(0);
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        weight.push_back(temp);
        friends[i].push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(weight[b]);
        friends[b].push_back(weight[a]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        sort(friends[i].begin(), friends[i].end(), greater<>());
        if(friends[i][0] == weight[i] && friends[i][0] != friends[i][1]) cnt++;
    }
    cout << cnt;
   return 0;
}
