#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    map<string, int> m_dictionary;
    vector<int> answer;
    int number = 1;
    string tmp2 = "";
    for(number = 1; number <= 26; number++)
        m_dictionary[tmp2 + (char)('A' - 1 + number)] = number;
    // 캐릭터형에다가 인트를 더해주면, 어찌됐든 int형으로 바뀌는듯, 그래서 char으로 바꿔주고 더함.
    // 중요, tmp2를 사용햇는데 이유는 "" 이게 문자열로 인식하지 않는거 같다. 
    // 그래서 tmp2라는 string 자료형을 만들어서 char와 더해주니 정상적으로 작동했다. 
    string save = "";
    for(int i = 0 ;  i < msg.size(); i++)
    {
        if(m_dictionary[save + msg[i]] > 0)
        {
            save = save + msg[i];
            if(i == msg.size() - 1)
                answer.push_back(m_dictionary[save]);
        }
        else
        {
            answer.push_back(m_dictionary[save]);
            m_dictionary[save + msg[i]] = number;
            number++;
            save = "";
            i--;
        }
    }
    return answer;
}
