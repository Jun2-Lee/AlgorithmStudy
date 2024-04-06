#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[21];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string calc;
		int num;
		cin >> calc;
		if (calc == "add") {
			cin >> num;
			S[num] = 1;
		}
		else if (calc == "remove") {
			cin >> num;
			S[num] = 0;
		}
		else if (calc == "check") {
			cin >> num;
			if (S[num] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (calc == "toggle") {
			cin >> num;
			if (S[num] == 1)
				S[num] = 0;
			else
				S[num] = 1;
		}
		else if (calc == "all") {
			for (int j = 0; j < 21; j++) {
				S[j] = 1;
			}
		}
		else {
			for (int j = 0; j < 21; j++) {
				S[j] = 0;
			}
		}

	}
	return 0;
}
