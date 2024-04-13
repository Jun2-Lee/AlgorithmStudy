#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int n;
int square[10001][6];
// 0, 5 짝 1, 3 짝 2, 4 짝

int find_back(int front) {
	switch (front) {
	case 0:
		return 5;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 0;
	}
}
//start는 아래 주사위의 윗면 값
void stack_s(int start, int depth, int temp_answer) {
	if (depth == n) {
		if (answer < temp_answer)
			answer = temp_answer;
		return;
	}
	// 현재 주사위 아랫면의 index
	int under = 0;
	for (int i = 0; i < 6; i++) {
		if (square[depth][i] == start) {
			under = i;
			break;
		}
	}
	// 현재 주사위 윗면의 index
	int top = find_back(under);

	// 위 아랫면이 아닌 것 중에 가장 큰 수
	int t_max = 0;
	for (int i = 0; i < 6; i++) {
		if (i != under && i != top) {
			if (t_max < square[depth][i])
				t_max = square[depth][i];
		}
	}

	stack_s(square[depth][top], depth + 1, temp_answer + t_max);
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int temp; cin >> temp;
			square[i][j] = temp;
		}
	}

	for (int i = 1; i <= 6; i++) {
		stack_s(i, 0, 0);
	}

	cout << answer;

	return 0;
}
