#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<int> tetris;
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
        if(!tetris.empty() && tetris.top() == s[i])
            tetris.pop();
        else tetris.push(s[i]);
    if(tetris.empty() == 1)
        answer = 1;
    return answer;
}
