#include <string>
#include <vector>

using namespace std;
string alpha[5] = {"A", "E", "I", "O", "U"};
string ans_str;
int cnt = -1;
int answer = 0;

void dfs(string cur) {
    cnt++;
    if(cur == ans_str) {
        answer = cnt;
        return;
    }
    if(cur.size() >= 5) return;
    for(int i = 0; i < 5; i++) {
        dfs(cur + alpha[i]);
    }
}

int solution(string word) {
    ans_str = word;
    dfs("");
    return answer;
}
