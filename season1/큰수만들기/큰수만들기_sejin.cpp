#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int idx = 0;
    string top_num = "0";
    string cur_num = "0";
    
    while (k && number.size() > 1) {
        top_num = "0";
        for (int i = 0; i < number.size(); i++) {
            if (i == number.size() - 1)
                cur_num = number.substr(0, number.size() - 1);
            else
                cur_num = number.substr(0, i) + number.substr(i + 1, number.size() - (i + 1));
            // if (stoi(cur_num) > stoi(top_num)) {
            //     top_num = cur_num;
            // }
            if (cur_num > top_num) {
                top_num = cur_num;
            }
        }
        number = top_num;
        k--;
    }
    return (number);
    // 1시간 21분 소요 실패 number 자리수 1000000 자리라서 stoi 범위 초과된다.
    // 문자열 끼리 비교해서 문자열 개수가 너무 많아 시간초과난다.
}
