#include <iostream>
#include <vector>

using namespace std;
int n, m;
int start, dest;
vector<int> list[100001];
vector<int> listR[100001];
bool visit_work[100001];
bool visit_home[100001];
bool visitR_work[100001];
bool visitR_home[100001];

void dfs(int cur, bool visit[], vector<int> v[])
{
    if (visit[cur])
        return;
    visit[cur] = true;
    for (auto next : v[cur])
    {
        dfs(next, visit, v);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        list[s].push_back(e);
        listR[e].push_back(s);
    }
    cin >> start >> dest;
    visit_home[dest] = true;
    visit_work[start] = true;
    dfs(start, visit_home, list);
    dfs(dest, visit_work, list);
    dfs(start, visitR_home, listR);
    dfs(dest, visitR_work, listR);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visit_home[i] && visit_work[i] && visitR_home[i] && visitR_work[i])
            answer++;
    }
    cout << answer - 2;
    return 0;
}
