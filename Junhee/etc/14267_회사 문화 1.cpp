#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

vector<int> people[100001];
int compliment[100001] = {
    0,
};
void dfs(int cur)
{
    //cout << cur << endl;
    for (int i = 0; i < people[cur].size(); i++)
    {
        compliment[people[cur][i]] += compliment[cur];
        dfs(people[cur][i]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp != -1)
        {
            people[temp].push_back(i);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int p, c;
        cin >> p >> c;
        compliment[p] += c;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << compliment[i] << " ";
    }
}
