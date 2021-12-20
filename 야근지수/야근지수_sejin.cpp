#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    sort(works.begin(), works.end(), greater<int>());
    int max;

    while (n) {
        max = works[0];
        if (max == 0)
            break;
        for (int i = 0; i < works.size() && n; i++) {
            if (max == works[i]) {
                works[i]--;
                n--;
            }
        }
    }

    for (auto &el : works) {
        answer += el * el;
    }

    return answer;
}
