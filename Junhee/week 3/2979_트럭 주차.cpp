#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int answer = 0;
	int time[101] = { 0, };

	for (int i = 0; i < 3; i++) {
		int arrive, left;
		cin >> arrive >> left;
		for (int j = arrive; j < left; j++) {
			time[j]++;
		}
	}
	for (int i = 0; i < 101; i++) {
		if (time[i] == 1) {
			answer += A;
		}
		if (time[i] == 2) {
			answer += 2 * B;
		}
		if (time[i] == 3) {
			answer += 3 * C;
		}
	}
	
	cout << answer;
	return 0;
}
