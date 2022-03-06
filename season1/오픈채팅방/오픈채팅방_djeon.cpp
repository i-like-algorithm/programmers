#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> vec_tmp;
    vector<vector<string> > split_record;
    map<string, string> id_matching;
    string str_tmp;
    
    for (int i = 0; i < record.size(); i++) {
        str_tmp = "";
        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ') {
                vec_tmp.push_back(str_tmp);
                str_tmp = "";
            } else {
                str_tmp += record[i][j];
            }
        }
        vec_tmp.push_back(str_tmp);
        split_record.push_back(vec_tmp);
        vec_tmp.clear();
        if (split_record.back()[0] == "Enter" || split_record.back()[0] == "Change") {
            id_matching[split_record.back()[1]] = split_record.back()[2];
        }
    }
    for (int i = 0; i < split_record.size(); i++) {
        if (split_record[i][0] == "Enter") {
            str_tmp = id_matching[split_record[i][1]] + "님이 들어왔습니다.";
            answer.push_back(str_tmp);
        } else if (split_record[i][0] == "Leave") {
            str_tmp = id_matching[split_record[i][1]] + "님이 나갔습니다.";
            answer.push_back(str_tmp);
        }
    }
    return answer;
}