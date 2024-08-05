#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long s, c;
vector<long long> pa;

long long make_chicken(int len) {
	long long cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += pa[i] / len;
	}
	return cnt;
}

long long make_ramen(long long len) {
	long long cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += pa[i];
	}
	
	return cnt - (len * c);
}

int main() {
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		long long temp;
		cin >> temp;
		pa.push_back(temp);
	}

	sort(pa.begin(), pa.end());
	
	long long start = 1;
	long long end = pa[pa.size() - 1];
	long long len = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = make_chicken(mid);
		if (cnt < c) {
			end = mid - 1;
		}
		else {
			len = mid;
			start = mid + 1;
		}
	}
	long long answer = make_ramen(len);
	cout << answer;
	return 0;
}
