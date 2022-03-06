#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int i = 0;
    vector<char> stack;
    
    while (i < s.size()) {
        if (!stack.empty() && stack.back() == s[i]) {
            stack.pop_back();
            i++;
        }
        else {
            stack.push_back(s[i]);
            i++;
        }
    }
    return stack.empty() ? 1 : 0;
}
