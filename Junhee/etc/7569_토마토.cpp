#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Tomato {
	int x;
	int y;
	int z;
};

int store[100][100][100] = {0, };
int m, n, h;
//6방향 탐색
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<Tomato> q;

// store 안에 있는 지 탐색
bool is_in(int x, int y, int z) {
	if (0 <= x && x < m && 0 <= y && y < n && 0 <= z && z < h) {
		return true;
	}
	return false;
}

void bfs() {
	while (!q.empty()) {
		Tomato temp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			int nz = temp.z + dz[i];
			if (is_in(nx, ny, nz) && store[nz][nx][ny] == 0) {
				store[nz][nx][ny] = store[temp.z][temp.x][temp.y] + 1;
				q.push({nx,ny,nz});
			}
		}
	}
}

int main() {
	cin >> n >> m >> h;
	// 창고 초기화
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				int temp;
				cin >> temp;
				store[i][j][k] = temp;
				if (temp == 1) {
					q.push({j,k,i});
				}
			}
		}
	}
	
	bfs();

	int answer = 0;
	bool flag = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (store[i][j][k] == 0) {
					flag = true;
				}
				else if (store[i][j][k] > 0) {
					answer = max(answer, store[i][j][k] - 1);
				}
			}
		}
	}

	if (flag) cout << -1;
	else cout << answer;

	return 0;
}
