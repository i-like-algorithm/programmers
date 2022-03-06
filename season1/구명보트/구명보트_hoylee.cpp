#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    int now_weight = 0;
    deque <int> dq;

    sort(people.begin(), people.end(), greater<int>());
    for (int i = 0; i < people.size(); i++)
        dq.push_back(people[i]);
     
    while(0 == dq.empty())
    {
        if(now_weight == 0)
        {
            now_weight += dq.front();
            dq.pop_front();
        }
        else if(limit - now_weight >= dq.back())
        {
            now_weight += dq.back();
            dq.pop_back();
        }
        else
        {
            now_weight = 0;
            answer++;
        }
    }
    return answer;
}
