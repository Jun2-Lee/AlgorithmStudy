#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int board[10][9];
int r1,c1, r2,c2,j,tmp;

queue<pair<pair<int,int>,int>> q;
bool visited[10][9];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int ddx[] = {-1, -1, 1, 1};
int ddy[] = {-1, 1, -1, 1};

int dddx[] = {-2, -2, 2, 2};
int dddy[] = {-2, 2, -2, 2};

bool is_in(int r, int c){
    if(r < 0 || c < 0 || r >9 || c > 8) return false;
    return true;
}

void bfs(){
    q.push({{r1,c1},0});
    visited[r1][c1] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(x==r2 && y == c2) {
            cout << cnt;
            return;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(board[nx][ny] == -2) continue;

            if(i == 0 || i==1){
                if(i==0) {
                    j=0; tmp=0;
                }
                else {
                    j=2; tmp=2;
                }
                for(; j<2+tmp;j++){
                    int nnx = nx + ddx[j];
                    int nny = ny + ddy[j];
                    if(board[nnx][nny]==-2) continue;

                    int nnnx = nx + dddx[j];
                    int nnny = ny + dddy[j];
                    if(is_in(nnnx, nnny) && !visited[nnnx][nnny]){
                        q.push({{nnnx, nnny}, cnt + 1});
                        visited[nnnx][nnny]= true;
                    }
                }
            }
            else{
                if(i==2) j=0;
                else j=1;
                for(; j<4;j+=2){
                    int nnx = nx + ddx[j];
                    int nny = ny + ddy[j];
                    if(board[nnx][nny]==-2) continue;

                    int nnnx = nx + dddx[j];
                    int nnny = ny + dddy[j];
                    if(is_in(nnnx, nnny) && !visited[nnnx][nnny]){
                        q.push({{nnnx, nnny}, cnt + 1});
                        visited[nnnx][nnny]= true;
                    }
                }
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;

    board[r2][c2] = -2;

    bfs();
}
