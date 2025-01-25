#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[4][4];
bool visit[4][4];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt = 0;
int n;
int answer = -1;

void dfs(int t_cnt, int beauty) {
    if(t_cnt == cnt) {
        answer = max(answer, beauty);
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j]) {
                visit[i][j] = true;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if(!visit[nx][ny]) {
                            visit[nx][ny] = true;
                            dfs(t_cnt + 1, beauty + tree[i][j] + tree[nx][ny]);
                            visit[nx][ny] = false;
                        }
                    }
                }
                visit[i][j] = false;
            }
        }
    }
    
}

int main(int argc, char** argv)
{
    cin >> n;
    if(n == 2) cnt = 2;
    else cnt = 4;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            tree[i][j] = temp;
        }
    }
    dfs(0, 0);
    cout << answer;
   return 0;
}
