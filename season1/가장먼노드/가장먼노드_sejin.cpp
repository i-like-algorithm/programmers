#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>> &arr, vector<int> &chk) {
    queue<int> q;
    chk[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < arr[node].size(); i++) {
            int next = arr[node][i];
            if (chk[next] == -1) {
                chk[next] = chk[node] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> arr(n + 1);
    vector<int> chk(n + 1, -1);
    
    for (int i = 0; i< edge.size(); i++) {
        arr[edge[i][0]].push_back(edge[i][1]);
        arr[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(arr, chk);
    
    return count(chk.begin(), chk.end(), *max_element(chk.begin(), chk.end()));
}
