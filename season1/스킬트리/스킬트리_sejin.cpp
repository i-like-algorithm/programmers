#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> skillmap;

    for (int i = 0; i < skill.size(); i++) {
        skillmap[skill[i]]++;
    }

    for (auto &el : skill_trees) {
        bool chk = true;
        string pure_skill;
        for (auto &el2 : el) {
            if (skillmap[el2]) {
                pure_skill += el2;
            }
        }
        if (skill.substr(0, pure_skill.size()) == pure_skill)
            answer++;
    }
    return answer;
}
