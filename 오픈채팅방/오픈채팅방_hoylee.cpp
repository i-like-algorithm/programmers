#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> split_record;
    map<string, string> m_user;
    string stringBuffer;
    
    for(int i = 0; i < record.size(); i++)
    {
        istringstream ss2(record[i]);
        while (getline(ss2, stringBuffer, ' ')){
            answer.push_back(stringBuffer);
        }
        
        split_record.push_back(answer);
        if(answer.size() == 3)
            m_user[answer[1]] = answer[2];
        answer.clear();      
    }
    for(int i = 0; i < record.size(); i++)
    {
        if("Enter" == split_record[i][0])
            answer.push_back(m_user[split_record[i][1]] + "님이 들어왔습니다.");
        else if("Leave" == split_record[i][0])
            answer.push_back(m_user[split_record[i][1]] + "님이 나갔습니다.");
    }

    return answer;
}
