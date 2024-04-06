#include <iostream>
#include <vector>

using namespace std;

int main() {
	int p;
	cin >> p;
	int line[20];
	while (p--) {
		int t, answer = 0;
		cin >> t;
		for (int i = 0; i < 20; i++) {
			int people;
			cin >> people;
			line[i] = people;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (line[i] > line[j]) answer++;
			}
		}
		cout << t << " " << answer << '\n';
	}



	return 0;
}
