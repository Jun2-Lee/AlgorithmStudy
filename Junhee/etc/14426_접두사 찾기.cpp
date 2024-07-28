#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_set<string> s;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		string sub_s = "";
		for (int j = 0; j < temp.size(); j++) {
			sub_s += temp[j];
			s.insert(sub_s);
		}
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (s.find(temp) != s.end())
			answer++;
	}

	cout << answer << endl;
	
	return 0;
}
