#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int N;
int map[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    deque<pair<int, int>> q;
    int visit[51][51];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visit[i][j] = -1;
        }
    }
    visit[0][0] = 0;
    q.push_back({0, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && visit[nx][ny] == -1)
            {
                if (map[nx][ny] == 1)
                {
                    q.push_front({nx, ny});
                    visit[nx][ny] = visit[x][y];
                }
                else
                {
                    q.push_back({nx, ny});
                    visit[nx][ny] = visit[x][y] + 1;
                }
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << visit[N - 1][N - 1];
}
