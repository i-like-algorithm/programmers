#include <string>
#include <vector>

using namespace std;

int binary_cnt(int num) {
    int cnt = 0;
    while (num) {
        if (num % 2)
            cnt++;
        num /= 2;
    }
    return (cnt);
}

int solution(int n) {
    int n_one_cnt = binary_cnt(n);
    int answer = n + 1;

    while (1) {
        if (n_one_cnt == binary_cnt(answer))
            break;
        answer++;
    }
    return answer;
}
