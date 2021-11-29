#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cal_arr_v(int n, long long idx) {
    int quotient = idx / n;
    int reminder = idx % n;

    if (quotient > reminder)
        return quotient + 1;
    return reminder + 1;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    int num = 0;
    for (long long i = left; i <= right; i++) {
        answer[num++] = cal_arr_v(n, i);
    }

    return answer;
}
