#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getBalanceStr(string str) {
    int cnt = 0;
    int i = 0;
    for ( ; i < str.size(); i++) {
        if (str[i] == '(')
            cnt++;
        else
            cnt--;
        if (i != 0 && cnt == 0)
            break ;
    }
    return i;
}

bool isRightStr(string str) {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    return cnt ? false : true;
}

string reverseStr(string str) {
    string result = str.substr(1, str.size() - 2);
    
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == '(')
            result[i] = ')';
        else
            result[i] = '(';
    }
    return result;
}

string convert(string str) {
    string u, v;
    string result;
    if (str.size() == 0)
        return "";
    int i = getBalanceStr(str);
    u = str.substr(0, i + 1);
    v = str.substr(i + 1);
    if (isRightStr(u)) {
        return u + convert(v);
    }
    else {
        result = "(";
        result += convert(v) + ")";
        result += reverseStr(u);
    }
    return result;
}

string solution(string p) {
    return convert(p);
}
