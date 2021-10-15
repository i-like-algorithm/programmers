#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int min2(int a, int speed)
{
    return (ceil(static_cast<float>(100 - a) / speed));
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int save;
    int cnt = 0;
    
    save = min2(progresses[0], speeds[0]);
    for (int i = 0; i < progresses.size(); i++)
    {
        cnt++;
        if(i + 1 < progresses.size() && save < min2(progresses[i + 1],speeds[i + 1]))
        {
            save = min2(progresses[i + 1], speeds[i + 1]);
            answer.push_back(cnt); 
            cnt = 0;
        }
    }
    answer.push_back(cnt);
    return answer;
}
