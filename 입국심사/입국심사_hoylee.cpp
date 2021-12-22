#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = 9223372036854775807;
    long long mid = 0;
    while(left<=right)
    {
        int flag = 0;
        mid = (left+right)/2;
        answer = 0;
        for(int i = 0; i < times.size(); i++)
        {
            answer += mid / times[i];
            if(mid % times[i] == 0)
                flag = 1;
            if (answer > n)
                break;
        }
        if(answer==n)
        {
            if(flag == 1)
            {
                return mid;
            }
            else right = mid - 1;
        }
        else if(answer>n)
            right = mid-1;
        else
            left = mid+1;
    }
    return answer = mid;
}
