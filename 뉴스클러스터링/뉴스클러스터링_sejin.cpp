#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

bool chkstr(string str) {
    if (str.size() != 2)
        return false;
    for (auto &el : str) {
        if (!isalpha(el))
            return false;
    }
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    string substr;
    int intersection = 0;
    int uni = 0;
    map<string, int> split_words1;
    map<string, int> split_words2;
    
    for (auto &el :str1)
        el = tolower(el);
    for (auto &el :str2)
        el = tolower(el);
    
    for (int i = 0; i < str1.size(); i++) {
        substr = str1.substr(i, 2);
        if (chkstr(substr))
            split_words1[substr]++;
    }
    for (int i = 0; i < str2.size(); i++) {
        substr = str2.substr(i, 2);
        if (chkstr(substr))
            split_words2[substr]++;
    }
    for (auto it = split_words1.begin(); it != split_words1.end(); it++) {
        if (it->second != 0 && split_words2[it->first] != 0)
            intersection += min(it->second, split_words2[it->first]);
    }
    for (auto it = split_words1.begin(); it != split_words1.end(); it++) {
        uni += max(it->second, split_words2[it->first]);
    }
    for (auto it = split_words2.begin(); it != split_words2.end(); it++) {
        if (split_words1[it->first] == 0)
            uni += it->second;
    }
    if (intersection == 0 && uni == 0)
        return 65536;
    return (double)intersection / uni * 65536;
}
