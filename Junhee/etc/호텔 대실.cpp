#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int day[60*24 * 10] = {0,};

int time_to_int(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i = 0; i < book_time.size(); i++) {
        int start = time_to_int(book_time[i][0]);
        int end = time_to_int(book_time[i][1]) + 10;
        for(int j = start; j < end; j++) {
            day[j]++;
            answer = max(answer, day[j]);
        }
    }
    
    return answer;
}
