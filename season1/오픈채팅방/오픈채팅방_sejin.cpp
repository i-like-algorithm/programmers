#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> array(record.size(), vector<string>());
    map<string, string> id_map;
    string stringbuffer;
    for (int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        while (getline(ss, stringbuffer, ' ')) {
            array[i].push_back(stringbuffer);
        }    
    }
    
    for (auto &el : array) {
        if (el[0] == "Enter" || el[0] == "Change") {
            id_map[el[1]] = el[2];
        }
    }
    
    for (auto &el : array) {
        if (el[0] == "Enter")
            answer.push_back(id_map[el[1]] + "님이 들어왔습니다.");
        else if(el[0] == "Leave")
            answer.push_back(id_map[el[1]] + "님이 나갔습니다.");
    }
    
    return answer;
}
