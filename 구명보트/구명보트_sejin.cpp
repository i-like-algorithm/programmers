#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight;
    
    sort(people.begin(), people.end());
    deque<int> my_dq(people.begin(), people.end());
    
    while (my_dq.size()) {
        weight = my_dq.back();
        my_dq.pop_back();
        if (my_dq.size()) {
            weight += my_dq.front();
            if (weight <= limit)
                my_dq.pop_front();
        }
        answer++;
    }
    
    return answer;
}
