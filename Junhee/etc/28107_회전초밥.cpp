#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> order[200001];
priority_queue<int, vector<int>, greater<int>> sushi;
int n, m;
int eat_cnt[100001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int temp;
			cin >> temp;
			order[temp].push(i);
		}
	}
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		sushi.push(temp);
	}
	while (!sushi.empty()) {
		int curr = sushi.top();
		sushi.pop();
		if (!order[curr].empty()) {
			eat_cnt[order[curr].top()]++;
			order[curr].pop();
		}
	}
	for (int i = 0; i < n; i++) {
		cout << eat_cnt[i] << " ";
	}
	return 0;
}
