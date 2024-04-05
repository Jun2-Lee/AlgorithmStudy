#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[201][201] = { 0, };
vector<int> trevel_list;
int trevel_ok[201] = { 0, };
int N, M;

void dfs(int start) {
	trevel_ok[start] = 1;
	for (int i = 0; i < N; i++) {
		if (map[start][i] == 1 && trevel_ok[i] == 0) {
			dfs(i);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		trevel_list.push_back(temp);
	}

	dfs(trevel_list[0] - 1);
	/*for (int i = 0; i < N; i++) {
		cout << trevel_ok[i] << " ";
	}*/
	bool answer = true;
	for (auto t : trevel_list) {
		if (trevel_ok[t - 1] == 0) {
			answer = false;
			break;
		}
	}

	if (answer) cout << "YES";
	else cout << "NO";

	return 0;
}
