#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second;
    priority_queue<int, vector<int>, greater<int>> p_q;
    
    for (auto &el : scoville) {
        p_q.push(el);
    }
    while (p_q.top() < K) {
        if (p_q.size() == 1)
            return (-1);
        first = p_q.top();
        p_q.pop();
        second = p_q.top();
        p_q.pop();
        p_q.push(first + second * 2);
        answer++;
    }
    return answer;
}
