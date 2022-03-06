#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    deque<string> dq;
    for(int i = 0; i < cities.size(); i++)
    {
        for(int j = 0; j < cities[i].size(); j++)
            cities[i][j] = tolower(cities[i][j]);
        auto it =find(dq.begin(), dq.end(), cities[i]);
        if(it != dq.end())
        { 
            dq.erase(it);
            answer += 1;
        }
        else answer += 5;

        dq.push_back(cities[i]);
        if(dq.size() == cacheSize + 1)
            dq.pop_front();
    }
    return answer;
}
