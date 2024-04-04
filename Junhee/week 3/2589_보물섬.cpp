#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer_map[51][51];
int map[51][51];
int n, m;

void bfs(int start, int end) {
	queue<pair<int, int>> q;
	int temp_map[51][51] = { 0, };
	q.push({ start,end });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == 0 && temp_map[nx][ny] == 0) {
				if (nx == start && ny == end) continue;
				temp_map[nx][ny] = temp_map[x][y] + 1;
				if (temp_map[nx][ny] > answer_map[nx][ny])
					answer_map[nx][ny] = temp_map[nx][ny];
				q.push({ nx, ny });
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << temp_map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp == 'W')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				bfs(i, j);
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (answer_map[i][j] > answer)
				answer = answer_map[i][j];
		}
	}
	cout << answer;
	return 0;
}
