#include <string>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int string_size = 0;
    int continuity_length = 1;
    for(int i = 1; i <= s.size() / 2; i++)
    {
        string_size = 0;
        for(int j = 1; j <= ceil((double)s.size() / i); j++)
        {
             if (j != ceil((double)s.size() / i) && (s.substr((j - 1) * i, i)  == s.substr((j - 1 + 1) * (i), i)))
                 continuity_length++;
             else
                 continuity_length *= -1;
            if(continuity_length < 0)
            {
                if(continuity_length != -1)
                    string_size += to_string(continuity_length * (-1)).size();
                if (j == ceil((double)s.size() / i) && s.size() % i != 0)
                    string_size += s.size() % i;
                else
                    string_size += i;
                continuity_length = 1;
            }
        }
        if(answer > string_size)
            answer = string_size;
    }
    return answer;
}
