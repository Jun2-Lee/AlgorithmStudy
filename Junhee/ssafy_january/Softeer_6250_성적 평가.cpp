#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> score[4];
vector<int> exist_score[4];
int n;

int main(int argc, char** argv)
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        score[3].push_back(0);
        exist_score[3].push_back(0);
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            score[i].push_back(temp);
            exist_score[i].push_back(temp);
            score[3][j] += temp;
            exist_score[3][j] += temp;
        }
    }
    for(int i = 0; i < 4; i++) {
        sort(score[i].begin(), score[i].end(), greater<>());
    }
    for(int i = 0; i < 4; i++) {
        unordered_map <int, int> m;
        m[score[i][0]] = 1;
        int prev = score[i][0];
        int cnt = 1;
        for(int j = 1; j < n; j++) {
            if(prev == score[i][j]) {
                cnt++;
                continue;
            }
            m[score[i][j]] = m[prev] + cnt;
            prev = score[i][j];
            cnt = 1;
        }
        for(int j = 0; j < n; j++) {
            cout << m[exist_score[i][j]] << " ";
        }
        cout << "\n";
    }
    
   return 0;
}
