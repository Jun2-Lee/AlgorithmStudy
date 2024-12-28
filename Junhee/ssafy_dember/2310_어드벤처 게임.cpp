#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cost[1001];
int visited[1001];
int sw;

void dfs(int now, int money, vector<int> way[]){
    if(sw == 1)
        return;
    
    // n번째 방 도착
    if(now == n) {
        sw = 1;
        return;
    }
    
    for(int i = 0; i < way[now].size(); i++) {
        int next = way[now][i];
        
        if(visited[next] == 1)
            continue;
        
        if(cost[next] > 0) {
            if(cost[next] > money)
                money = cost[next];
        }
        else
            money += cost[next];
        
        if(money < 0)
            return;
        
        visited[next] = 1;
        dfs(next, money, way);
        visited[next] = 0;
    }
}

int main() {
    while(true){
        vector<int> way[1001];
        cin >> n;
        if(n == 0)
            break;
       
        sw = 0;
        for(int i = 1; i <= n; i++){
            char info;
            int c;
            cin >> info >> c;
            while(true) {
                int next;
                cin >> next;
                if(next == 0)
                    break;
                way[i].push_back(next);
            }
            if(info == 'T')
                cost[i] = -c;
            else
                cost[i] = c;
        }
        
        if(cost[1] >= 0) {
            visited[1] = 1;
            dfs(1, cost[1], way);
        }
        
        if(sw == 1)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
        
        for(int i=0; i<=n; i++){
            cost[i] = 0;
            visited[i] = 0;
        }
        
    }
    return 0;
}
