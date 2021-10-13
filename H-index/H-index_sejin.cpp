#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
        for (int j = citations[i]; j > 0; j--) {
            if (i + 1 >= j && answer < j) {
                answer = j;
            }
        }
    }
    return answer;
}
