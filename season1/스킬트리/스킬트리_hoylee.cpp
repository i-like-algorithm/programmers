#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for(int i = 0 ; i < skill.size(); i++)
        m[skill[i]] = i + 1;
    for(int i = 0 ; i < skill_trees.size(); i++)
    {
        int skill_index = 0;
        //string tmp = skill;
        for(int j = 0; j < skill_trees[i].size(); j++)
        {
            if(m[skill_trees[i][j]] != 0)
            {
                if(skill_index == m[skill_trees[i][j]] - 1)
                    skill_index++;
                else break;
            }
            if(j == skill_trees[i].size() - 1)
                answer++;
        }
    }
    return answer;
}
