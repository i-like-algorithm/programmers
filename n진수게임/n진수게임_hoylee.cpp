#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    vector<string> digit_num = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    string answer = "";
    int cnt = 0;
    int every_char_cnt = 0;
    while(1)
    {
        string tmp = "";
        int two_convert = cnt;
        if(two_convert == 0)
            tmp = "0";
        while(two_convert != 0)
        {
            tmp = digit_num[two_convert % n] + tmp;
            two_convert = two_convert / n;
        }
        for(int i = 0; i < tmp.size(); i++)
        {
            if(every_char_cnt % m == p - 1)
                answer += tmp[i];
            if(answer.size() == t)
                return answer;
            every_char_cnt++;
        }
        cnt++;
    }
    return answer;
}
