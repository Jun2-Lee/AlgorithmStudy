#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b) {
    return a.first < b.first;
}

int main()
{

    
    int dayCount = 1;

    while (true)
    {
        bool attend[50];
        int p;
        int cnt = 0;

        for(int i = 0; i < 50; i++) {
            attend[i] = false;
        }
        cin >> p;
        if(p == 0) break;

        vector< pair<int, pair<int, int>> > parties;
        parties.reserve(p);

        for (int i = 0; i < p; i++)
        {
            int startTime, endTime;
            cin >> startTime >> endTime;
            if (startTime == endTime) {
                continue;
            }
            int time = endTime - startTime;
            int start = startTime * 2;
            int end = endTime * 2;
            parties.push_back({time, {start, end}});
        }

        sort(parties.begin(), parties.end(), compare);

        for (int i = 0; i < parties.size(); i++)
        {
            int cur_start = parties[i].second.first;
            int cur_end   = parties[i].second.second;
            for (int j = cur_start; j < cur_end; j++)
            {
                if (!attend[j])
                {
                    attend[j] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << "On day " << dayCount
             << " Emma can attend as many as "
             << cnt << " parties.\n";

        dayCount++;
    }
}
