#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int max_plus = 0;
int max_price = 0;
int d_dis[4] = {10,20,30,40};
vector<int> discount;

void dfs(vector<vector<int>> users, vector<int> emoticons) {
    if(discount.size() == emoticons.size()){
        int plus = 0;
        int sum = 0;
        
        for(int i = 0; i < users.size(); i++) {
            int t_sum = 0;
            for(int j = 0; j < emoticons.size(); j++) {
                if(discount[j] >= users[i][0]) {
                    t_sum += emoticons[j] * (100 - discount[j]) / 100;
                }
            }
            
            if(t_sum >= users[i][1]) {
                plus++;
            }
            else {
                sum += t_sum;
            }
        }
        if(max_plus < plus) {
            max_plus = plus;
            max_price = sum;
        }
        else if(max_plus == plus && max_price < sum) {
            max_price = sum;
        }
        
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        discount.push_back(d_dis[i]);
        dfs(users, emoticons);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users, emoticons);
    answer.push_back(max_plus);
    answer.push_back(max_price);
    return answer;
}
