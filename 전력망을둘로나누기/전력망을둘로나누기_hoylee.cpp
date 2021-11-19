#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

void bfs(queue<int> &q, map<int,vector<int>> &m_wires, vector<int> &checker, int &count)
{
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i=0; i< m_wires[x].size(); i++){ 
            int y = m_wires[x][i]; 
            if(!checker[y - 1]){
                q.push(y);
                checker[y - 1] = true; 
                count++;
            } 
        } 
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999999;
    int count1 = 0;
    int count2 = 0;
    vector<int> checker(n, 0);
    map<int, vector<int>> m_wires;
    
    for(int i = 0; i < wires.size(); i++)
    {
        m_wires[wires[i][0]].push_back(wires[i][1]);
        m_wires[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0; i < wires.size(); i++)
    {
        queue<int> q1;
        queue<int> q2;
        
        q1.push(wires[i][0]);
        q2.push(wires[i][1]);
        checker.assign(n, 0);
        checker[wires[i][0] - 1] = 1;
        checker[wires[i][1] - 1] = 1;

        for(int j = 0; j < m_wires[wires[i][0]].size(); j++)
        {
            if(m_wires[wires[i][0]][j] != wires[i][1])
                q1.push(m_wires[wires[i][0]][j]);
        }
        for(int j = 0; j < m_wires[wires[i][1]].size(); j++)
        {
            if(m_wires[wires[i][1]][j] != wires[i][0])
                q2.push(m_wires[wires[i][1]][j]);
        }
        count1 = 1;
        count2 = 1;

        bfs(q1, m_wires, checker, count1);
        bfs(q2, m_wires, checker, count2);
        if (abs(count1 - count2) < answer)
            answer = abs(count1 - count2);
    }
    return answer;
}
