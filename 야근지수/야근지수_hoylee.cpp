#include <string>
#include <vector>
#include <queue> 
using namespace std;
 
void wekly_work(int &n, priority_queue<long long> &pq)
{
    while(n != 0 && !(pq.empty()))
    {
        int max_num = pq.top();
        
        pq.pop();
        if(max_num != 0)
            pq.push(--max_num);
        n--;
    }
    return ;
}

void Night_Shift(priority_queue<long long> &pq, long long &answer)
{
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    
    for(int i = 0; i < works.size(); i++)
        pq.push(works[i]);
    wekly_work(n, pq);
    Night_Shift(pq, answer);

    return answer;
}
