#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> &numbers, int index, int value, int &answer, int target)
{
    if (index == numbers.size() )
    {
        if (target == value)
            answer++;
        return;
    }
    DFS(numbers, index + 1, value + numbers[index], answer, target);
    DFS(numbers, index + 1, value - numbers[index], answer, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, 0, 0, answer, target);
    return answer;
}
