#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map(8, vector<int>(8));
vector<vector<int>> t_map(8, vector<int>(8));
int answer = 0;
int n; 
int m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> bfs_q;

void bfs(int x, int y) {
	bfs_q.push(make_pair(x, y));
	while (!bfs_q.empty()) {
		int t_x = bfs_q.front().first;
		int t_y = bfs_q.front().second;
		bfs_q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t_x + dx[i];
			int ny = t_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (t_map[nx][ny] == 0) {
					bfs_q.push(make_pair(nx, ny));
					t_map[nx][ny] = 3;
				}
			}
		}
	}
}

int check_safe() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t_map[i][j] == 0)
				cnt++;
		}
	}
	if (answer < cnt) {
		answer = cnt;
	}
		
	
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v;
			cin >> v;
			map[i][j] = v;
		}
	}

	for (int i = 0; i < n * m; i++) {
		for (int j = i + 1; j < n * m; j++) {
			for (int k = j + 1; k < n * m; k++) {
				copy(map.begin(), map.end(), t_map.begin());
				int i_n = i / m, i_m = i % m;
				int j_n = j / m, j_m = j % m;
				int k_n = k / m, k_m = k % m;
				if (t_map[i_n][i_m] != 0 || t_map[j_n][j_m] != 0 || t_map[k_n][k_m] != 0)
					continue;
				t_map[i_n][i_m] = 1;
				t_map[j_n][j_m] = 1;
				t_map[k_n][k_m] = 1;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b++) {
						if (t_map[a][b] == 2) {
							bfs(a, b);
						}
					}
				}
				check_safe();
			}
		}
	}
	cout << answer;
}
