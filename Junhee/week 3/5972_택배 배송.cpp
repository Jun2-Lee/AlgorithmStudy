#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;



vector<pair<int, int>> vec[50001];
priority_queue<pair<int, int>> pq;
vector<int> answer(50001, 99999999);

void dijkstra(int start) {
	pq.push({ 0, start });
	answer[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first * -1;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int next_cost = vec[cur][i].second + cost;

			if (next_cost < answer[next]) {
				answer[next] = next_cost;
				pq.push({ next_cost * -1, next });
			}
		}
	}
}

int main() {

	int N, M; 
	cin >> N >> M;

	while (M--) {
		int s, e, c;
		cin >> s >> e >> c;
		vec[s].push_back({e, c});
		vec[e].push_back({s, c});
	}

	dijkstra(1);

	cout << answer[N];

	return 0;
}
