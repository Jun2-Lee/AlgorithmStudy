#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n;
vector<int> tree[500001];
bool visit[500001] = { false, };
int cnt = 0;

void dfs(int node, int depth) {
	if (node != 1 && tree[node].size() == 1) {
		cnt += depth;
		return;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		if (visit[node] == false) {
			visit[node] = true;
			dfs(tree[node][i], depth + 1);
			visit[node] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	dfs(1, 0);

	if (cnt % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}
