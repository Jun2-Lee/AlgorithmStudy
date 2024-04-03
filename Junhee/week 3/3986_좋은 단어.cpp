#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		stack<char> s;
		for (int j = 0; j < temp.size(); j++) {
			if (!s.empty()) {
				if (s.top() == temp[j]) {
					s.pop();
				}
				else {
					s.push(temp[j]);
				}
			}
			else {
				s.push(temp[j]);
			}
		}
		if (s.empty())
			ans++;
		
	}
	cout << ans;
	return 0;
}
