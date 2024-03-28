#include <iostream>

using namespace std;

int answer[26];
char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] == alpha[j]) answer[j]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
