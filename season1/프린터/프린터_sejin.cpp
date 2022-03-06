#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag;
    
    deque<pair<int, int>> my_dq;
    
    for (int i = 0; i < priorities.size(); i++) {
        if (i == location)
            my_dq.push_back(pair<int, int>(priorities[i], 1));
        else
            my_dq.push_back(pair<int, int>(priorities[i], 0));
    }
    
    while (!my_dq.empty()) {
        flag = false;
        for (int i = 1; i < my_dq.size(); i++) {
            if (my_dq.front().first < my_dq[i].first) {
                my_dq.push_back(my_dq.front());
                my_dq.pop_front();
                flag = true;
                break;
            }
        }
        if (flag == false) {
            answer++;
            if (my_dq.front().second)
                return (answer);
            my_dq.pop_front();            
        }
    }
    return answer;
}
