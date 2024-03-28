#include <iostream>

using namespace std;

int main() {
	string s;
	bool answer = true;
	cin >> s;
	int start = 0, end = s.size() - 1;
	while (start <= end) {
		if (s[start] != s[end]) {
			answer = false;
			break;
		}
		start++;
		end--;
	}
	if (answer) cout << 1;
	else cout << 0;
	return 0;
}
