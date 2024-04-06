#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> score;

int toSecond(string t) {
	int second = 0;
	string m = t.substr(0, 2);
	second += stoi(m) * 60;
	string s = t.substr(3, 2);
	second += stoi(s);
	return second;
}

string toMinute(int t) {
	string m = to_string(t / 60);
	string s = to_string(t % 60);
	if (m.size() == 1) m = "0" + m;
	if (s.size() == 1) s = "0" + s;
	return m + ":" + s;
}

int main() {
	int score1 = 0, score2 = 0;
	int time1 = 0, time2 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int team; string t;
		cin >> team;
		cin >> t;
		score.push_back({ team, toSecond(t) });
	}
	int start = 0;
	for (auto s : score) {
		int t = s.first;
		if (score1 > score2) time1 += s.second - start;
		if (score2 > score1) time2 += s.second - start;
		if (t == 1) score1++;
		else score2++;
		start = s.second;
	}
	if (score1 > score2) time1 += 2880 - start;
	if (score2 > score1) time2 += 2880 - start;
	
	cout << toMinute(time1) << '\n' << toMinute(time2);
	
	/*for (auto i : score) {
		cout << i.first << " " << i.second << endl;
	}*/
	return 0;
}
