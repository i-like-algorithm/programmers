#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class cmp {
public:
    bool operator() (const vector<int> &x, const vector<int> &y) {
        if (x[1] > y[1])
            return true;
        else
            return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b){
        return (a[0] < b[0] ? true : false);
    });
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int i = 0;
    int time = jobs[0][0];
    for (; i < jobs.size(); i++) {
        if (jobs[i][0] <= time) {
            pq.push(jobs[i]);
        }
        else
            break;
    }     
    
    while (!pq.empty()) {
        answer += (time - pq.top()[0] + pq.top()[1]);
        time += pq.top()[1];
        pq.pop();
        for (; i < jobs.size(); i++) {
            if (time < jobs[i][0] && pq.empty())
                time = jobs[i][0];
            if (jobs[i][0] <= time) {
                pq.push(jobs[i]);
            }
            else
                break;
                
        }
    }
    
    return answer / jobs.size();
}
