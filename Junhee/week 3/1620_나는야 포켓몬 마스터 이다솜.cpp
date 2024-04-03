#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> pocketmon_dict;
	unordered_map<string, int> pocketmon_map;
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string pocketmon;
		cin >> pocketmon;
		pocketmon_dict.push_back(pocketmon);
		pocketmon_map[pocketmon] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		string ans;
		cin >> ans;
		if ('0' <= ans[0] && ans[0] <= '9') {
			int num;
			num = stoi(ans);
			answer.push_back(pocketmon_dict[num - 1]);
		}
		else {
			answer.push_back(to_string(pocketmon_map[ans]));
		}
	}
	for (auto a : answer) {
		cout << a << endl;
	}

	return 0;
}
