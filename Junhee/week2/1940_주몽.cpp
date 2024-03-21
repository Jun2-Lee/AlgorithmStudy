#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ingre;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ingre.push_back(temp);
	}

	sort(ingre.begin(), ingre.end());
	int start = 0, end = ingre.size() - 1;
	int answer = 0;

	while (start < end) {
		if (ingre[start] + ingre[end] == m) {
			answer++;
			start++;
			end--;
		}
		else if(ingre[start] + ingre[end] < m){
			start++;
		}
		else {
			end--;
		}
	}
	cout << answer;

	return 0;
}
