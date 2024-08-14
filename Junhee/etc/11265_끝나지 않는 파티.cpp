#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <string>

using namespace std;

int party_map[501][501];
int n, m;

void pw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				party_map[j][k] = min(party_map[j][k], party_map[j][i] + party_map[i][k]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			party_map[i][j] = temp;
		}
	}
	pw();
	for (int i = 0; i < m; i++) {
		int s, d, p;
		cin >> s >> d >> p;
		if (party_map[s - 1][d - 1] <= p) {
			cout << "Enjoy other party" << endl;
		}
		else {
			cout << "Stay here" << endl;
		}

	}
	return 0;
}
