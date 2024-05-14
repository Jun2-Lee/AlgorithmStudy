#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> skyline;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		while (!skyline.empty() && skyline.top() >= y) {
			if (skyline.top() != y) ans++;
			skyline.pop();
		}
		skyline.push(y);

	}
	skyline.push(0);
	while (!skyline.empty() && skyline.top() >= 0) {
		if (skyline.top() != 0) ans++;
		skyline.pop();
	}
	

	cout << ans;



	return 0;
}
