#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int tmp;
    int tmp2;
    priority_queue<int,vector<int>,greater<int>> min_pq (scoville.begin(),scoville.end());
    
    while(!min_pq.empty())
    {
        answer++;
        tmp = min_pq.top();
        min_pq.pop();
        if(min_pq.empty())
            return -1;
        tmp2 = min_pq.top();
        min_pq.pop();
        min_pq.push(tmp + (tmp2 * 2));
        if(min_pq.top() > K)
            return answer;
    }
    return -1;
}
