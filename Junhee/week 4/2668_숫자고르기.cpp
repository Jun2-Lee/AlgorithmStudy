#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n;
int num[101];
vector<int> answer;
bool visit[101] = { false, };

void dfs(int cur, int start) {
	if (visit[cur]) {
		if (cur == start) {
			answer.push_back(start);
		}
		return;
	}

	visit[cur] = true;
	dfs(num[cur], start);
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		num[i] = temp;
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}
	cout << answer.size() << endl;
	for (auto a : answer) {
		cout << a << " ";
	}

	return 0;
}
