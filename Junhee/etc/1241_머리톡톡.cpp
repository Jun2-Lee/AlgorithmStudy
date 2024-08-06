#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int num[1000001] = { 0, };
int answer[100001];
int student[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		student[i] = temp;
		num[temp]++;
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 1; j <= sqrt(student[i]); j++) {
			if (student[i] % j == 0) {
				if (student[i] == j * j) {
					cnt += num[j];
				}
				else {
					cnt += num[j];
					cnt += num[student[i] / j];
				}
			}
		}
		answer[i] = cnt - 1;
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
