#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(vector<int> &number, int sum, int &target, int idx, int &answer) {
    if (number.size() == idx) {
        if (sum == target)
            answer++;
        return;
    }
    DFS(number, sum - number[idx], target, idx + 1, answer);
    DFS(number, sum + number[idx], target, idx + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, 0, target, 0, answer);
    return answer;
}
