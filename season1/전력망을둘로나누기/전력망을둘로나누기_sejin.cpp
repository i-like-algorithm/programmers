#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int start, vector<int> &check, vector<vector<int>> &adjust_list, vector<int> cut_wire) {
    queue<int> q;
    check[start] = 0;
    int cnt = 1;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < adjust_list[node].size(); i++) {
            int next = adjust_list[node][i];
            if (next == cut_wire[1] - 1 && node == cut_wire[0] - 1) {}
            else if (next == cut_wire[0] - 1 && node == cut_wire[1] - 1) {}            
            // else if (check[next] == -1 && next != cut_wire[1] - 1) {
            else if (check[next] == -1) {
                check[next] = check[node] + 1;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    vector<vector<int>> adjust_list(n);
    
    for (int i = 0; i < wires.size(); i++) {
        adjust_list[wires[i][0] - 1].push_back(wires[i][1] - 1);
        adjust_list[wires[i][1] - 1].push_back(wires[i][0] - 1);
    }
    
    for (int i = 0; i < wires.size(); i++) {
        vector<int> check(n, -1);
        vector<int> result;
        for (int j = 0; j < n; j++) {
            if (check[j] == -1) {
                result.push_back(bfs(j, check, adjust_list, wires[i])); 
            }
        }
        if (answer > abs(result[0] - result[1]))
            answer = abs(result[0] - result[1]);
    }
    
    return answer;
}
