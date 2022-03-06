#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int one_count =0;
    int zero_count = 0;
    int repeat_count = 0;
    while(s != "1")
    {
        one_count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if('1' == s[i])
                one_count++;
            else zero_count++;
        }
        s = "";
        while(one_count != 0)
        {
            s += (one_count % 2) + '0';
            one_count = one_count / 2 ;
        }
        repeat_count++;
    }
    return {repeat_count, zero_count};
}
