#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int limit[1001] = { 0, };

struct homework {
	int day;
	int pay;
};

// 돈 많이 주는 순으로 정렬
bool compare(homework h1, homework h2) {
	if (h1.pay == h2.pay) return h1.day > h2.day;
	return h1.pay > h2.pay;
}

int main() {
	cin >> n;
	vector<homework> h_list;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int d, p;
		cin >> d >> p;
		h_list.push_back({ d, p });
	}

	sort(h_list.begin(), h_list.end(), compare);
	
	// 돈 많이 받는 순으로 최대한 일을 뒤로 미루기
	for (int i = 0; i < h_list.size(); i++) {
		for (int j = h_list[i].day; j > 0; j--) {
			if (limit[j] == 0) {
				limit[j] = h_list[i].pay;
				answer += h_list[i].pay;
				break;
			}
		}
	}


	cout << answer << endl;
	return 0;
}
