#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;
vector<int> possible_numbers;
bool visit[7];

void dfs(string cur, string numbers) {
    int len = s.size();
    if(cur.size() != 0) {
        s.insert(stoi(cur));
        if(len != s.size()) possible_numbers.push_back(stoi(cur));
    }
    if(cur.size() == numbers.size()) return;
    for(int i = 0; i < numbers.size(); i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(cur + numbers[i], numbers);
            visit[i] = false;
        }
    }
}

bool is_prime(int num) {
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    dfs("", numbers);
    for(int i = 0; i < possible_numbers.size(); i++) {
        if(possible_numbers[i] < 2) continue;
        if(is_prime(possible_numbers[i])) answer++;
    }
    
    return answer;
}
