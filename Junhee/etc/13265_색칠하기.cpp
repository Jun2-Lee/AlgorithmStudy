#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 색깔은 1 or 2
int printing[1000][1000];
int node[1000] = { 0, };
int n, m;
bool is_possible;

void dfs(int curr) {
	//cout << curr << " ";
	for (int i = 0; i < n; i++) {
		if (printing[curr][i] == 1 && node[i] == 0) {
			if (node[curr] == 1) node[i] = 2;
			else node[i] = 1;
			dfs(i);
		}
		if (printing[curr][i] == 1 && node[curr] == node[i])
			is_possible = false;
	}
}

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n >> m;
		is_possible = true;
		for (int i = 0; i < n; i++) {
			node[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printing[i][j] = 0;
			}
		}
		// 그래프 지도 만들기
		for (int i = 0; i < m; i++) {
			int s, e;
			cin >> s >> e;
			printing[s - 1][e - 1] = 1;
			printing[e - 1][s - 1] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (node[i] == 0) {
				node[i] = 1;
				dfs(i);
			}
		}
		if (is_possible) cout << "possible" << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}
