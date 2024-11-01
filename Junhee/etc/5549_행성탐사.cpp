#include <iostream>
#include <string>

using namespace std;

int m = 0, n = 0, k = 0;
int a, b, c, d;
char arr[1001][1001];
int pos[1001][1001][3] = { 0 };
string temp;

int main() {
	cin >> m >> n >> k;

    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	for (int i = 1; i <= m; i++) {
		cin >> temp;
		for (int j = 1; j <= n; j++)
			arr[i][j] = temp[j - 1];
	}

	for (int i = 1; i <= n; i++) {
		if (arr[1][i] == 'J') pos[1][i][0] = 1;
		else if (arr[1][i] == 'O') pos[1][i][1] = 1;
		else if (arr[1][i] == 'I') pos[1][i][2] = 1;

		pos[1][i][0] += pos[1][i - 1][0];
		pos[1][i][1] += pos[1][i - 1][1];
		pos[1][i][2] += pos[1][i - 1][2];
	}

	for (int i = 1; i <= m; i++) {
		if (arr[i][1] == 'J') pos[i][1][0] = 1;
		else if (arr[i][1] == 'O') pos[i][1][1] = 1;
		else if (arr[i][1] == 'I') pos[i][1][2] = 1;

		pos[i][1][0] += pos[i - 1][1][0];
		pos[i][1][1] += pos[i - 1][1][1];
		pos[i][1][2] += pos[i - 1][1][2];
	}
	
	for (int i = 2; i <= m ; i++) {
		for (int j = 2; j <= n ; j++) {
			pos[i][j][0] = pos[i - 1][j][0] + pos[i][j - 1][0] - pos[i - 1][j - 1][0];
			pos[i][j][1] = pos[i - 1][j][1] + pos[i][j - 1][1] - pos[i - 1][j - 1][1];
			pos[i][j][2] = pos[i - 1][j][2] + pos[i][j - 1][2] - pos[i - 1][j - 1][2];

			if (arr[i][j] == 'J') pos[i][j][0] += 1;
			else if (arr[i][j] == 'O') pos[i][j][1] += 1;
			else if (arr[i][j] == 'I') pos[i][j][2] += 1;
		}
	}


	for (int i = 0; i < k; i++) { 
		cin >> a >> b >> c >> d;
		int jungle = pos[c][d][0] - pos[a - 1][d][0] - pos[c][b - 1][0] + pos[a - 1][b - 1][0];
		int ocean  = pos[c][d][1] - pos[a - 1][d][1] - pos[c][b - 1][1] + pos[a - 1][b - 1][1];
		int ice    = pos[c][d][2] - pos[a - 1][d][2] - pos[c][b - 1][2] + pos[a - 1][b - 1][2];
		cout << jungle << ' ' << ocean << ' ' << ice << '\n';
	}

}
