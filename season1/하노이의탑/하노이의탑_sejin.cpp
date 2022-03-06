#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>> &answer, int start, int mid, int end, int n) {
    if (n == 0)
        return ;
    hanoi(answer, start, end, mid, n - 1);
    answer.push_back({start, end});
    hanoi(answer, mid, start, end, n - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, 1, 2, 3, n);
    return answer;
}
