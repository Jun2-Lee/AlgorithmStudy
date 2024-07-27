#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cctv {
	int x, y, type;
};

int n, m;
int cctv_num = 0;
int answer = 99;
int map[8][8];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<cctv> cctv_list;


int count_blank() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void fill_map(int x, int y, int direction) {
	// 방향 정하고, map을 채워나가기
	int dir = direction % 4;
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (map[nx][ny] == 6) break;
			if (map[nx][ny] == 0) map[nx][ny] = -1;
		}
		else break;
		x = nx; y = ny;
	}
}

void select_type(cctv c, int direction) {
	// 각각의 타입에 따라 몇 방향을 볼 건지 체크
	switch (c.type) {
	case 1:
		fill_map(c.x, c.y, direction);
		break;
	case 2:
		fill_map(c.x, c.y, direction);
		fill_map(c.x, c.y, direction + 2);
		break;
	case 3:
		fill_map(c.x, c.y, direction);
		fill_map(c.x, c.y, direction + 1);
		break;
	case 4:
		fill_map(c.x, c.y, direction);
		fill_map(c.x, c.y, direction + 1);
		fill_map(c.x, c.y, direction + 2);
		break;
	case 5:
		fill_map(c.x, c.y, direction);
		fill_map(c.x, c.y, direction + 1);
		fill_map(c.x, c.y, direction + 2);
		fill_map(c.x, c.y, direction + 3);
		break;
	}
}

void dfs(int cnt) {
	// cctv 전부 확인하면 사각지대 카운팅
	if (cnt == cctv_num) {
		answer = min(answer, count_blank());
		return;
	}
	int temp_map[8][8];
	for (int i = 0; i < 4; i++) {
		// 초기 상태의 map 임시 저장
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				temp_map[j][k] = map[j][k];
			}
		}

		select_type(cctv_list[cnt], i);

		// 다음 cctv로 이동
		dfs(cnt + 1);

		// 다음 방향을 위한 초기화
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				map[j][k] = temp_map[j][k];
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (1 <= temp && temp <= 5) {
				cctv_num++;
				cctv_list.push_back({ i, j, temp });
			}
		}
	}

	dfs(0);

	cout << answer;
	return 0;
}
