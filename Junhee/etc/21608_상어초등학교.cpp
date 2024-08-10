#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct student {
	int num;
	int f_friend[4];
};


int n;
vector<student> friends;
int school[21][21];
int s_cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int f_cnt = 0;
int b_cnt = 0;

bool compare(student a, student b) {
	return a.num < b.num;
}

// 자리 전부 돌면서 점수 계산
int calc_answer() {
	// 학생을 번호순으로 정렬
	sort(friends.begin(), friends.end(), compare);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t_cnt = 0;
			student t_s = friends[school[i][j] - 1];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					for (int f = 0; f < 4; f++) {
						if (school[nx][ny] == t_s.f_friend[f]) {
							t_cnt++;
						}
					}
				}
			}
			if (t_cnt == 1) cnt += 1;
			if (t_cnt == 2) cnt += 10;
			if (t_cnt == 3) cnt += 100;
			if (t_cnt == 4) cnt += 1000;
		}
	}
	return cnt;
}

// 주변 좋아하는 사람 탐색
int calc_favorite(int x, int y, student curr) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			for (int j = 0; j < 4; j++) {
				if (school[nx][ny] == curr.f_friend[j])
					cnt++;
			}
		}
	}
	return cnt;
}

// 주변 빈자리 탐색
int calc_blank(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (school[nx][ny] == 0)
				cnt++;
		}
	}
	return cnt;
}

// 자리 정하기 시작
void select_seat(int idx) {
	int x = -1, y = -1;
	student curr_s = friends[idx];
	int favorite_friend = 0;
	int blank_seat = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 현재 자리가 빈자리이면
			if (school[i][j] == 0) {
				// 이번이 첫 빈자리일 때 초기화(3번 조건)
				if (x == -1 && y == -1) {
					x = i; y = j;
				}
				// 현재 자리 기준 주변 좋아하는 친구 탐색
				favorite_friend = calc_favorite(i, j, curr_s);
				// 현재 자리 기준 주변 빈자리 탐색
				blank_seat = calc_blank(i, j);
				// 이전에 봐왔던 자리보다 주변에 좋아하는 친구가 많으면
				if (favorite_friend > f_cnt) {
					b_cnt = blank_seat;
					f_cnt = favorite_friend;
					x = i; y = j;
				}
				// 좋아하는 친구 수는 같지만 주변 빈자리가 더 많으면
				else if (favorite_friend == f_cnt) {
					if (blank_seat > b_cnt) {
						b_cnt = blank_seat;
						x = i; y = j;
					}
				}
			}
		}
	}
	// 자리 확정
	school[x][y] = curr_s.num;
}

int main() {
	cin >> n;
	s_cnt = n * n;
	for (int i = 0; i < s_cnt; i++) {
		student t_s;
		cin >> t_s.num;
		for (int j = 0; j < 4; j++) {
			cin >> t_s.f_friend[j];
		}
		friends.push_back(t_s);
	}

	// 시작 자리는 무조건 (1,1)
	school[1][1] = friends[0].num;
	for (int i = 1; i < s_cnt; i++) {
		select_seat(i);
		f_cnt = 0;
		b_cnt = 0;
	}

	int answer = calc_answer();
	cout << answer;
	return 0;
}
