#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> building;
vector<vector<int>> tree(11);

void make_tree(int start, int end, int depth) {
	if (start >= end)
		return;
	int parent = (start + end) / 2;
	tree[depth].push_back(building[parent]);
	make_tree(start, parent, depth + 1);
	make_tree(parent + 1, end, depth + 1);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;
	int b_num;
	for(int i = 0; i < pow(2, k) - 1; i++) {
		cin >> b_num;
		building.push_back(b_num);
		
	}

	make_tree(0, building.size(), 0);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
