#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int dist[201][201];
vector<int> friends;

void floyd_warshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            dist[i][j] = 987654321;
        }
    }
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        dist[s][e] = c;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        friends.push_back(temp);
    }
    floyd_warshall();
    int min = 987654321;
    vector<int> answer;
    for(int i = 1; i <= n; i++) {
        int d = 0;
        for(int j = 0; j < k; j++) {
            if(dist[i][friends[j]] != 987654321 && dist[friends[j]][i] != 987654321) {
                d = max(dist[i][friends[j]] + dist[friends[j]][i], d);
            }
        }
        if(min > d) {
            answer.clear();
            answer.push_back(i);
            min = d;
        }
        else if (min == d) {
            answer.push_back(i);
        }
    }
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}
