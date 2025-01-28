#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
int map[26][26];
int s_x, s_y;
int dx[4] = {1,0,-1,0}; // 아래, 오른쪽, 위, 왼쪽(v, >, ^, <)
int dy[4] = {0,1,0,-1};
char dir[4] = {'v', '>', '^', '<'};

bool check() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1) return false;
        }
    }
    return true;
}

bool is_range(int x, int y) {
    if(0 <= x && x < h && 0 <= y && y < w) return true;
    return false;
}

bool can_go(int x, int y, int d) {
    for(int i = 1; i <= 2; i++) {
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if(is_range(nx, ny) && map[nx][ny] == 1) map[nx][ny] = 0;
        else return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < w; j++) {
            if(temp[j] == '.') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bool flag = false;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 0) continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(0 <= x && x < h && 0 <= y && y < w && map[x][y] == 1) cnt++;
            }
            if(cnt == 1) {
                s_x = i;
                s_y = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    int d = -1;
    for(int i = 0; i < 4; i++) {
        int x = s_x + dx[i];
        int y = s_y + dy[i];
        if(is_range(x, y) && map[x][y] == 1) d = i;
    }
    cout << s_x + 1 << " " << s_y + 1 << "\n";
    cout << dir[d] << "\n";
    map[s_x][s_y] = 0;
    int x = s_x;
    int y = s_y;
    string answer = "";
    while(true) {
        if(check()) break;
        if(can_go(x, y, d)) {
            x += dx[d] * 2;
            y += dy[d] * 2;
            answer += "A";
            continue;
        }
        int temp_d = (d + 1) % 4;
        if(can_go(x, y, temp_d)) {
            d = temp_d;
            x += dx[d] * 2;
            y += dy[d] * 2;
            answer += "LA";
            continue;
        }
        temp_d = (d + 3) % 4;
        if(can_go(x, y, temp_d)) {
            d = temp_d;
            x += dx[d] * 2;
            y += dy[d] * 2;
            answer += "RA";
            continue;
        }
    }
    cout << answer;
   return 0;
}
