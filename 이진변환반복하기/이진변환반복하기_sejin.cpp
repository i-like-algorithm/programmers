#include <string>
#include <vector>

using namespace std;

string to_binary(int num) {
    string result;
    
    while (num) {
        result = result + to_string(num % 2);
        num /= 2;
    }
    return (result);
}

int cnt_zero(string str) {
    int cnt = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0')
            cnt++;
    }
    return (cnt);
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int cnt = 0;
    while (s != "1") {
        cnt = cnt_zero(s);
        answer[1] += cnt;
        s = to_binary(s.size() - cnt);
        answer[0]++;
    }
    
    return answer;
}
