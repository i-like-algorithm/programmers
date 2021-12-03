#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int find_dic(string &msg, vector<string> &dic) {
    string input;
    int idx = 0;
    
    for (int i = 0; i < msg.size(); i++) {
        input = msg.substr(0, msg.size() - i);
        auto it = find(dic.begin(), dic.end(), input);
        if (it != dic.end()) {
            msg = msg.substr(input.size());
            idx = it - dic.begin();
            if (msg.size() != 0) {
                dic.push_back(input + msg[0]);
            }
            return (idx);
        }
            
    }
    return (-1);
}

void LZW(vector<int> &answer, string &msg, vector<string> &dic) {
    while (!msg.empty()) {
        int idx = find_dic(msg, dic);
        if (idx != -1) {
            answer.push_back(idx);
        }        
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    vector<string> dic(27);
    dic[0] = 'x';
    for (int i = 1; i < 27; i++) {
        dic[i] = 'A' + (i - 1);
    }
    LZW(answer, msg, dic);
    
    return answer;
}
