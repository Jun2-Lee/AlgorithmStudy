#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, t;
bool answer = false;

void dfs(string temp) {
    if (temp.size() < s.size()) return; // 탐색 종료 조건 (s보다 짧아지면 불가능)
    if (temp == s) { 
        answer = true;
        return;
    }

    // 'A'로 끝나는 경우 'A' 제거
    if (temp[temp.size() - 1] == 'A') {
        dfs(temp.substr(0, temp.size() - 1));
    }

    // 'B'로 시작하는 경우 뒤집고 'B' 제거
    if (temp[0] == 'B') {
        reverse(temp.begin(), temp.end());
        dfs(temp.substr(0, temp.size() - 1));
    }
}

int main() {
    cin >> s >> t;
    dfs(t);
    cout << (answer ? 1 : 0);
}
