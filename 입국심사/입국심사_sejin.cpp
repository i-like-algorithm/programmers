#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long left = times[0];
    long long right = (long long)times[times.size() - 1] * n;
    long long answer = right;
    
    while (left <= right) {
        long long mid = (right + left) / 2;
        long long audit_cnt = 0;
        
        for (int i = 0; i < times.size(); i++) {
            audit_cnt += mid / times[i];
        }   
        if (audit_cnt >= n) {
            answer = min(mid, answer);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }   
    return answer;
}
