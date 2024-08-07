#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int s_x, s_y, e_x, e_y;
	cin >> s_x >> s_y >> e_x >> e_y;
	long long cnt = 0;
	int min_s = min(s_x, s_y);
	int max_s = max(e_x, e_y);
	for (int i = s_x; i < e_x; i ++) {
		if (i % 2 == 1) {
			int temp = min(e_y, i);
			if (temp - s_y > 0) {
				cnt += temp - s_y;
			}
		}
	}
	for (int i = s_y; i < e_y; i ++) {
		if (i % 2 == 1) {
			int temp = min(e_x, i);
			if (temp - s_x > 0) {
				cnt += temp - s_x;
			}
		}
	}
	for (int i = min_s; i < max_s; i++) {
		if (i % 2 == 1) {
			if (s_x <= i && i < e_x && s_y <= i && i < e_y) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
