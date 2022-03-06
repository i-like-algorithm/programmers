#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;

    for(int i = 0; i < s.size(); i++)
    {
        int cnt = 0;
        int j = 0;
        for(; j + i < s.size() && i - j >= 0; j++)
        {
            if(s[i + j] != s[i - j])
                break ;
        }
        if((j - 1) * 2 + 1 > answer)
            answer = (j - 1) * 2 + 1;
        j = 0;
        for(; j + i + 1 < s.size() && i - j >= 0; j++)
        {
            if(s[i - j] != s[i + 1 + j])
                break;
        }
        if(j * 2 > answer)
            answer = j * 2;
    }
    return answer;
}
