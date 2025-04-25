#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(true) {
        int temp = pq.top();
        pq.pop();
        if(pq.empty() && temp < K) {
            answer = -1;
            break;
        }
        if(temp >= K) break;
        temp += pq.top() * 2;
        pq.pop();
        pq.push(temp);
        answer++;
    }
    return answer;
}
