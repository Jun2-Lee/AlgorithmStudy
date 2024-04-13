#include <iostream>
#include <vector>

using namespace std;

long long n, m;
long long big_square[51][51];
long long answer = 0;

long long calc(long long start_x, long long end_x, long long start_y, long long end_y) {
	long long sum = 0;
	for (long long i = start_x; i < end_x; i++) {
		for (long long j = start_y; j < end_y; j++) {
			sum += big_square[i][j];
		}
	}
	return sum;
}

void divide_row() {
	for (long long i = 0; i < n - 1; i++) {
		for (long long j = i + 1; j < n; j++) {
			long long a = calc(0, i, 0, m);
			long long b = calc(i, j, 0, m);
			long long c = calc(j, n, 0, m);
			long long temp = a * b * c;
			if (answer < temp)
				answer = temp;
		}
	}
}

void divide_col() {
	for (long long i = 0; i < m - 1; i++) {
		for (long long j = i + 1; j < m; j++) {
			long long a = calc(0, n, 0, i);
			long long b = calc(0, n, i, j);
			long long c = calc(0, n, j, m);
			long long temp = a * b * c;
			if (answer < temp)
				answer = temp;
		}
	}
}

void divide_row_col() {
	for (long long i = 0; i < n - 1; i++) {
		for (long long j = 0; j < m; j++) {
			long long a = calc(0, i, 0, m);
			long long b = calc(i, n, 0, j);
			long long c = calc(i, n, j, m);
			long long temp = a * b * c;
			//cout << a << " " << b << " " << c << " " << temp << endl;
			if (answer < temp)
				answer = temp;

			a = calc(i, n, 0, m);
			b = calc(0, i, 0, j);
			c = calc(0, i, j, m);
			temp = a * b * c;
			//cout << a << " " << b << " " << c << " " << temp << endl;
			if (answer < temp)
				answer = temp;
		}
	}
}

void divide_col_row() {
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < m; j++) {
			long long a = calc(0, i, 0, j);
			long long b = calc(i, n, 0, j);
			long long c = calc(0, n, j, m);
			long long temp = a * b * c;
			//cout << a << " " << b << " " << c << " " << temp << endl;
			if (answer < temp)
				answer = temp;

			a = calc(0, i, j, m);
			b = calc(i, n, j, m);
			c = calc(0, n, 0, j);
			temp = a * b * c;
			//cout << a << " " << b << " " << c << " " << temp << endl;
			if (answer < temp)
				answer = temp;
		}
	}
}

int main() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		string num; cin >> num;
		for (long long j = 0; j < num.size(); j++) {
			long long temp; 
			temp = num[j] - '0';
			big_square[i][j] = temp;
		}
	}

	divide_row();
	divide_col();
	divide_row_col();
	divide_col_row();

	cout << answer;
	return 0;
}
