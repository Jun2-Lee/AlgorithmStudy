#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[126][126] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int dijkstra(int n) {
	vector<vector<int>> cost(n, vector<int>(n, 99999999));
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ map[0][0] * -1,{0,0} });
	cost[0][0] = map[0][0];
	while (!pq.empty()) {
		int cur_cost = pq.top().first * -1;
		int x = pq.top().second.first; int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				int next_cost = cur_cost + map[nx][ny];
				if (next_cost < cost[nx][ny]) {
					cost[nx][ny] = next_cost;
					pq.push({ next_cost * -1, {nx,ny} });
				}
			}
		}
	}
	/*for (auto i : cost) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	return cost[n - 1][n - 1];
}

int main() {
	int cnt = 0;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		cnt++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cost;
				cin >> cost;
				map[i][j] = cost;
			}
		}
		cout << "Problem " << cnt << ": " << dijkstra(n) << endl;
	}


	return 0;
}
