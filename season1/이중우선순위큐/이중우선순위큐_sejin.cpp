#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> greater_pq;
    priority_queue<int, vector<int>> less_pq;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            greater_pq.push(stoi(operations[i].substr(2)));
            less_pq.push(stoi(operations[i].substr(2)));
            cnt++;
        }
        else if (operations[i] == "D 1" && cnt > 0) {
            less_pq.pop();
            cnt--;
        }
        else if (operations[i] == "D -1" && cnt > 0) {
            greater_pq.pop();
            cnt--;
        }
        if (cnt == 0) {
            while (!greater_pq.empty()) {
                cout << greater_pq.top() << endl;
                greater_pq.pop();
            }
            while (!less_pq.empty()) {
                cout << less_pq.top() << endl;
                less_pq.pop();
            }
        }
    }
    if (cnt == 0)
        return {0, 0};
    else
        return {less_pq.top(), greater_pq.top()};
}
