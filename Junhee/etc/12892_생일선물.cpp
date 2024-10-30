#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, D;
vector<pair<int, int>> gift;
int main()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        int P, V;
        cin >> P >> V;
        gift.push_back({P, V});
    }
    sort(gift.begin(), gift.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first; });
    int start = 0, end = 0;
    long long diff = 0;
    long long satisfaction = 0;
    long long answer = -1;

    while (true)
    {
        if (end == gift.size())
            break;
        if (gift[end].first - gift[start].first < D)
        {
            // cout << start << " " << end << " diff = " << gift[end].first - gift[start].first << " , satisfaction = ";
            satisfaction += gift[end++].second;
            // cout << satisfaction << "\n";
        }
        else
        {
            satisfaction -= gift[start++].second;
        }
        answer = max(answer, satisfaction);
    }
    cout << answer;
    return 0;
}
