#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int answer[26] = { 0, };
	char ans = '?';
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
		answer[s[i] - 'A']++;
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (answer[i] > max) {
			max = answer[i];
			ans = i + 'A';
		}
		else if (answer[i] == max) {
			ans = '?';
		}
	}

	cout << ans;

	return 0;
}
