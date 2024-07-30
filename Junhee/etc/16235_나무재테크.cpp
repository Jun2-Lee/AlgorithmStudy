#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };
int map[10][10] = { 0, };
int nutrient[10][10] = { 0, };
int n, m, k;
deque<int> alive_tree[10][10];

bool compare(int a, int b) {
	return a < b;
}

void spring_summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// spring
			int idx = -1;
			for (int k = 0; k < alive_tree[i][j].size(); k++) {
				if (map[i][j] >= alive_tree[i][j][k]) {
					map[i][j] -= alive_tree[i][j][k];
					alive_tree[i][j][k]++;
				}
				else {
					idx = k;
					break;
				}
			}
			// summer
			if (idx != -1) {
				for (int k = alive_tree[i][j].size() - 1; k >= idx; k--) {
					map[i][j] += alive_tree[i][j][k] / 2;
					alive_tree[i][j].pop_back();
				}
			}
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < alive_tree[i][j].size(); k++) {
				if (alive_tree[i][j][k] % 5 == 0) {
					for (int idx = 0; idx < 8; idx++) {
						int nx = i + dx[idx];
						int ny = j + dy[idx];
						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							alive_tree[nx][ny].push_front(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += nutrient[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 5;
			int temp;
			cin >> temp;
			nutrient[i][j] = temp;
		}
	}
	for (int i = 0; i < m; i++) {
		int t_x, t_y, t_a;
		cin >> t_x >> t_y >> t_a;
		alive_tree[t_x - 1][t_y - 1].push_back(t_a);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(alive_tree[i][j].begin(), alive_tree[i][j].end(), compare);
		}
	}
	
	for (int i = 0; i < k; i++) {
		spring_summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += alive_tree[i][j].size();
		}
	}

	cout << answer;

	return 0;
}
