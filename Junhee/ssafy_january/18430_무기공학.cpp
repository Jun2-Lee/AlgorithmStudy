#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int arr[6][6];
bool ch[6][6];
int N, M;
int res = 0;

void dfs(int x, int y, int sum) {
	if (y == M) {
		y = 0;
		x++;
	}
	if (x == N) {
		res = max(res, sum);
		return;
	}
	if (!ch[x][y]) {
		if (x + 1 < N && y - 1 >= 0 && !ch[x + 1][y] && !ch[x][y - 1]) {
			ch[x + 1][y] = true;
			ch[x][y - 1] = true;
			ch[x][y] = true;
			int tmp = sum + (arr[x + 1][y] + (arr[x][y] * 2) + arr[x][y - 1]);
			dfs(x, y + 1, tmp);
			ch[x + 1][y] = false;
			ch[x][y - 1] = false;
			ch[x][y] = false;
		}
		if (x - 1 >= 0 && y - 1 >= 0 && !ch[x - 1][y] && !ch[x][y - 1]) {
			ch[x - 1][y] = true;
			ch[x][y - 1] = true;
			ch[x][y] = true;
			int tmp = sum + (arr[x - 1][y] + (arr[x][y] * 2) + arr[x][y - 1]);
			dfs(x, y + 1, tmp);
			ch[x - 1][y] = false;
			ch[x][y - 1] = false;
			ch[x][y] = false;
		}
		if (x - 1 >= 0 && y + 1 < M && !ch[x - 1][y] && !ch[x][y + 1]) {
			ch[x - 1][y] = true;
			ch[x][y + 1] = true;
			ch[x][y] = true;
			int tmp = sum + (arr[x - 1][y] + (arr[x][y] * 2) + arr[x][y + 1]);
			dfs(x, y + 1, tmp);
			ch[x - 1][y] = false;
			ch[x][y + 1] = false;
			ch[x][y] = false;
		}
		if (x + 1 < N && y + 1 < M && !ch[x + 1][y] && !ch[x][y + 1]) {
			ch[x + 1][y] = true;
			ch[x][y + 1] = true;
			ch[x][y] = true;
			int tmp = sum + (arr[x + 1][y] + (arr[x][y] * 2) + arr[x][y + 1]);
			dfs(x, y + 1, tmp);
			ch[x + 1][y] = false;
			ch[x][y + 1] = false;
			ch[x][y] = false;
		}
	}
	dfs(x, y + 1, sum);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	dfs(0,0,0);
	cout << res << "\n";
	return 0;
}
