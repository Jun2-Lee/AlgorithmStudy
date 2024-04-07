#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int h, w;
	int answer = 0;
	cin >> h >> w;
	vector<int> map;
	for (int i = 0; i < w; i++) {
		int temp;
		cin >> temp;
		map.push_back(temp);
	}
	for (int i = 1; i < map.size() - 1; i++) {
		int left_max = 0, right_max = 0;
		for (int j = 0; j < i; j++) {
			if (map[j] > left_max) left_max = map[j];
		}
		for (int j = i + 1; j < map.size(); j++) {
			if (map[j] > right_max) right_max = map[j];
		}
		if(min(left_max, right_max) - map[i] > 0)
			answer += min(left_max, right_max) - map[i];
	}
	cout << answer;
	return 0;
}
