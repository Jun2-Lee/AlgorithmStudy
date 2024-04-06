#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<pair<int, int>> p_list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		p_list.push_back({ w, h });
	}
	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (p_list[i].first < p_list[j].first && p_list[i].second < p_list[j].second)
				rank++;
		}
		cout << rank << " ";
	}
	return 0;
}
