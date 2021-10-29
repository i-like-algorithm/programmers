#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void routine(string &answer, string u, string v, int cnt, string p)
{
    int i;
    if (p == "")
        return ;
    for(i = 0; i < p.size(); i++)
    {
        u += p[i];
        if((p[i] == '(' && ++cnt) || (p[i] == ')' && --cnt))
            ;
        else
            break;
    }
    if (i == p.size())
        v = "";
    else v = p.substr(i + 1);
    if(u[0] == '(')
    {
        answer += u;
        routine(answer, "", "", 0, v);
    }
    else if (u[0] == ')')
    {
        string tmp = "(";
        answer += "(";
        routine(answer, "", "", 0, v);
        answer += ")";
        for(int z = 1; z < u.size() - 1; z++)
            if(u[z] == '(')
                answer += ')';
            else if(u[z] == ')')
                answer += '(';
    }
}

string solution(string p) {
    string answer = "";

    if(p.size() == 0) return answer;
    routine(answer, "", "", 0, p);
    
    return answer;
}
