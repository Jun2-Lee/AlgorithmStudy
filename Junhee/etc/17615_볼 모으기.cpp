#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string ball;
	int n;
	cin >> n >> ball;
	int max_cnt = 500000;
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ball[i] == 'B') flag = true;
		if (flag && ball[i] == 'R') cnt++;
	}
	max_cnt = min(max_cnt, cnt);
	cnt = 0; flag = false;
	for (int i = n - 1; i >= 0; i--) {
		if (ball[i] == 'B') flag = true;
		if (flag && ball[i] == 'R') cnt++;
	}
	max_cnt = min(max_cnt, cnt);
	cnt = 0; flag = false;
	for (int i = 0; i < n; i++) {
		if (ball[i] == 'R') flag = true;
		if (flag && ball[i] == 'B') cnt++;
	}
	max_cnt = min(max_cnt, cnt);
	cnt = 0; flag = false;
	for (int i = n - 1; i >= 0; i--) {
		if (ball[i] == 'R') flag = true;
		if (flag && ball[i] == 'B') cnt++;
	}
	max_cnt = min(max_cnt, cnt);
	cout << max_cnt;
	return 0;
}
