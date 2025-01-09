#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;
vector<int> gift;
vector<int> box;
vector<int> people;

int main() {
    cin >> n >> k;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        gift.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        cin >> temp;
        box.push_back(temp);
    }
    for(int i = 0; i < k; i++) {
        cin >> temp;
        people.push_back(temp);
    }

    sort(box.begin(), box.end());
    sort(gift.begin(), gift.end(), greater<int>());

    unordered_map<int, int> chosen_count;
    for(int i = 0; i < k; i++) {
        chosen_count[people[i]]++;
    }

    int mybox = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(chosen_count[box[i]] > 0) {
            chosen_count[box[i]]--;
        } else {
            mybox = box[i];
            break;
        }
    }

    int answer = -1;
    for(int i = 0; i < n; i++) {
        if(mybox >= gift[i]) {
            answer = gift[i];
            break;
        }
    }

    cout << answer;
    return 0;
}
