#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n, vector<int>& team1, vector<int>& team2) {
    vector<int> color(n + 1, -1);
    
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            team1.push_back(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) { 
                        color[neighbor] = 1 - color[node]; 
                        if (color[neighbor] == 0) {
                            team1.push_back(neighbor);
                        } else {
                            team2.push_back(neighbor);
                        }
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        int dislike_count;
        cin >> dislike_count;
        for (int j = 0; j < dislike_count; ++j) {
            int disliked_person;
            cin >> disliked_person;
            graph[i].push_back(disliked_person);
            graph[disliked_person].push_back(i);
        }
    }

    vector<int> team1, team2;
    isBipartite(graph, n, team1, team2);

    sort(team1.begin(), team1.end());
    sort(team2.begin(), team2.end());

    cout << team1.size() << endl;
    for (int member : team1) {
        cout << member << " ";
    }
    cout << endl;

    cout << team2.size() << endl;
    for (int member : team2) {
        cout << member << " ";
    }
    cout << endl;

    return 0;
}
