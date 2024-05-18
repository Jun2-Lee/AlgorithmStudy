#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int mid = n / 2;
	int answer = 0;

	for (int i = 0; i <= mid; i++) {
		string line;
		cin >> line;
		for (int j = mid - i; j <= mid + i; j++) {
			answer += line[j] - '0';
		}
	}
	for (int i = 1; i < n - mid; i++) {
		string line;
		cin >> line;
		for (int j = i; j < n - i; j++) {
			answer += line[j] - '0';
		}
	}

	cout << answer;


	return 0;
}
