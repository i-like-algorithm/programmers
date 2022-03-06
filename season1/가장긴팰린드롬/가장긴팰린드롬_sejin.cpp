#include <iostream>
#include <string>
using namespace std;

int palin(const string &s, int left, int right, const int &length) {
    int result = 0;

    if (right - left == 2)
        result = 1;

    while (1) {
        if (right > length - 1 || left < 0 || s[left] != s[right])
            break ;
        left--;
        right++;
        result += 2;
    }
    return result;
}

int find_palin(const string &s, const int &idx, const int &length) {
    int odd_palin = palin(s, idx - 1, idx + 1, length);
    int even_palin = palin(s, idx, idx + 1, length);
    return (odd_palin > even_palin ? odd_palin : even_palin);
}

int solution(string s)
{
    int answer = 0;
    int palin_val;

    for (int i = 0; i < s.size(); i++) {
        palin_val = find_palin(s, i, s.size());
        if (palin_val > answer)
            answer = palin_val;
    }
    return answer;
}
