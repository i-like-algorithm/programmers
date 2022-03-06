#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    string comp = "";
    vector<pair<string, int>> my_stack;
    
    for (int i = 1; i < s.size(); i++) {
        my_stack.clear();
        for (int j = 0; j < s.size(); ) {
            if (s.size() - j < i)
                my_stack.push_back(pair<string, int>(s.substr(j), 1));
            else {
                if (my_stack.empty() || my_stack[my_stack.size() - 1].first != s.substr(j, i))
                    my_stack.push_back(pair<string, int>(s.substr(j, i), 1));
                else
                    my_stack[my_stack.size() - 1].second++;
            }
            j += i;
        }
        for (auto it = my_stack.begin(); it != my_stack.end(); it++) {
            if (it->second > 1)
                comp += (it->first + to_string(it->second));
            else
                comp += it->first;
        }
        if (comp.size() < answer)
            answer = comp.size();
        comp = "";
    }

    return answer;
}
