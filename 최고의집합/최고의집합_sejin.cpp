#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n, s / n);
    int remain = s % n;
    if (s / n == 0)
        return (vector<int>(1, -1));
    if (remain == 0) {
        return (answer);
    }
    else {
        for (int i = 0; i < remain; i++) {
            answer[n - 1 - i]++;
        }
    }
    return answer;
}
