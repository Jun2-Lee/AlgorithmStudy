#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
bool visit[20001];

int main(int argc, char** argv)
{
    cin >> n >> k;
    
    string s;
    
    cin >> s;
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            int start = max(0, i - k);
            int end = min(n - 1, i + k);
            
            for (int j = start; j <= end; j++) {
                if (!visit[j] && s[j] == 'H') {
                    if (i == j) continue;
                    
                    visit[j] = true;
                    count++;
                    break;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
