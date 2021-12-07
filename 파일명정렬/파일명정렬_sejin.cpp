#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct s_token {
    string head;
    int number;
    int idx;
    string orig;
}               t_token;

int get_head_idx(const string &str) {
    int result = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            result = i - 1;
            break;
        }
    }
    return result;
}

int get_num_idx(const string &str, int start) {
    int result = 0;
    
    for (int i = start; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            result = i - 1;
            break;
        }
    }
    return result;
}

bool cmp(const t_token &a, const t_token &b) {
    if (a.head != b.head) {
        return (a.head < b.head);
    }
    if (a.head == b.head && a.number != b.number) {
        return (a.number < b.number);
    }
    return (a.idx < b.idx);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<t_token> split_files(files.size());
    
    for (int i = 0; i < files.size(); i++) {
        int head_idx = get_head_idx(files[i]);
        int num_idx = get_num_idx(files[i], head_idx + 1);
        string head_str = files[i].substr(0, head_idx + 1);
        string num_str = files[i].substr(head_idx + 1, num_idx - (head_idx + 1) + 1);
        transform(head_str.begin(), head_str.end(), head_str.begin(), ::toupper);
        split_files[i].head = head_str;
        split_files[i].number = stoi(num_str);
        split_files[i].idx = i;
        split_files[i].orig = files[i];
    }
    
    sort(split_files.begin(), split_files.end(), cmp);
    for (auto &el : split_files) {
        answer.push_back(el.orig);
    }
    
    return answer;
}
