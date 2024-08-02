#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
string a, b;
int burb[100001];
int burb2[100001];
int want[100001];

void click(int idx) {
	burb[idx - 1] = (burb[idx - 1] + 1) % 2;
	burb[idx] = (burb[idx] + 1) % 2;
	burb[idx + 1] = (burb[idx + 1] + 1) % 2;
}

void first_click() {
	burb[0] = (burb[0] + 1) % 2;
	burb[1] = (burb[1] + 1) % 2;
}

int main() {
	cin >> n;
	cin >> a >> b;
	int answer = 999999999;
	for (int i = 0; i < n; i++) {
		burb[i] = a[i] - '0';
		burb2[i] = a[i] - '0';
		want[i] = b[i] - '0';
	}
	int temp_ans = 0;
	for (int i = 1; i < n; i++) {
		if (burb[i - 1] != want[i - 1]) {
			click(i);
			temp_ans++;
		}
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (burb[i] != want[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		answer = min(answer, temp_ans);
	}

	
	// 원래 상태로
	for (int i = 0; i < n; i++) {
		burb[i] = burb2[i];
	}
	first_click();
	temp_ans = 1;
	for (int i = 1; i < n; i++) {
		if (burb[i - 1] != want[i - 1]) {
			click(i);
			temp_ans++;
		}
	}

	flag = true;
	for (int i = 0; i < n; i++) {
		if (burb[i] != want[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		answer = min(answer, temp_ans);
	}

	if (answer == 999999999)
		answer = -1;
	cout << answer;
	return 0;
}
