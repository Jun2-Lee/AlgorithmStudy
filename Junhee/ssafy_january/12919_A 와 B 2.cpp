#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, t;
bool answer = false;

void dfs(string temp) {
    if (temp.size() < s.size()) return;
    if (temp == s) { 
        answer = true;
        return;
    }

    if (temp[temp.size() - 1] == 'A') {
        dfs(temp.substr(0, temp.size() - 1));
    }

    if (temp[0] == 'B') {
        reverse(temp.begin(), temp.end());
        dfs(temp.substr(0, temp.size() - 1));
    }
}

int main() {
    cin >> s >> t;
    dfs(t);
    if(answer) cout << 1;
    else cout << 0;
}
