#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<double> f;
    for (int i = 0; i < 4; i++) {
        double temp;
        cin >> temp;
        f.push_back(temp);
    }

    vector<pair<int, int>> matches = {
        {1, 2}, {1, 3}, {1, 4},
        {2, 3}, {2, 4}, {3, 4}
    };

    queue<pair<pair<int, double>, vector<double>>> q;
    q.push({{0, 1.0}, {0, 0, 0, 0}});
    double ans = 0;

    while (!q.empty()) {
        int idx = q.front().first.first;
        double prob = q.front().first.second;
        vector<double> p = q.front().second;
        q.pop();

        if (idx == matches.size()) {
            vector<pair<double, int>> rank;
            for (int i = 0; i < 4; i++) {
                rank.push_back({p[i], i + 1});
            }
            sort(rank.begin(), rank.end(), [](pair<double, int>& a, pair<double, int>& b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second < b.second;
            });
            if (rank[0].second == 1 || rank[1].second == 1) {
                ans += prob;
            }
            continue;
        }

        int i = matches[idx].first - 1;
        int j = matches[idx].second - 1;

        double prob_i = (4 * f[i]) / (5 * f[i] + 5 * f[j]);
        vector<double> p_i = p;
        p_i[i] += 3;
        q.push({{idx + 1, prob * prob_i}, p_i});

        double prob_j = (4 * f[j]) / (5 * f[i] + 5 * f[j]);
        vector<double> p_j = p;
        p_j[j] += 3;
        q.push({{idx + 1, prob * prob_j}, p_j});

        double prob_draw = (f[i] + f[j]) / (5 * f[i] + 5 * f[j]);
        vector<double> p_draw = p;
        p_draw[i] += 1;
        p_draw[j] += 1;
        q.push({{idx + 1, prob * prob_draw}, p_draw});
    }

    printf("%0.3lf", round(ans * 100000) / 1000.0);


    return 0;
}
