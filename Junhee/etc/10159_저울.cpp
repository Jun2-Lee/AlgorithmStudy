#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool heavy[100][100];
bool light[100][100];

void floyd_warshall() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 현재 값 or 방문 안 한 것중에 가까운 것
				heavy[i][j] = heavy[i][j] || (heavy[i][k] && heavy[k][j]);
				light[i][j] = light[i][j] || (light[i][k] && light[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			heavy[i][j] = false;
			light[i][j] = false;
			if(i == j) {
				heavy[i][j] = true;
				light[i][j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int h, l;
		cin >> h >> l;
		heavy[l - 1][h - 1] = true;
		light[h - 1][l - 1] = true;
	}

	floyd_warshall();

	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if (!heavy[i][j] && !light[i][j]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
