#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    
    long long cnt = 0;
    for(; left <= right; left++)
    {
        if(left / n > left % n)
            answer[cnt] = left / n + 1;
        else
            answer[cnt] = left % n + 1;
        cnt++;
    }
    return answer;
}
