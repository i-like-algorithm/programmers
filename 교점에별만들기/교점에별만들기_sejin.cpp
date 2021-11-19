#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void combi(vector<vector<long long>> &line, vector<vector<long long>> &comb, int r, int idx, int depth, vector<vector<long long>> &result) {
    if (r == 0) {
        if ((comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]) == 0
            || (comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]) == 0)
            return ;
            
        if (((comb[0][1] * comb[1][2] - comb[0][2] * comb[1][1]) % (comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]) == 0) 
            && ((comb[0][2] * comb[1][0] - comb[0][0] * comb[1][2]) % (comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]) == 0)) {
            long long x = (comb[0][1] * comb[1][2] - comb[0][2] * comb[1][1]) / (comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]);
            long long y = (comb[0][2] * comb[1][0] - comb[0][0] * comb[1][2]) / (comb[0][0] * comb[1][1] - comb[0][1] * comb[1][0]);
            result.push_back({x, y});
        }
    }
    else if (depth == line.size())
        return ;
    else {
        comb[idx] = line[depth];
        combi(line, comb, r - 1, idx + 1, depth + 1, result);
        combi(line, comb, r, idx, depth + 1, result);
    }
}

vector<string> solution(vector<vector<int>> line) {
    vector<vector<long long>> result;
    vector<vector<long long>> line_long(line.size(), vector<long long>(3, 0));
    
    for (int i = 0; i < line_long.size(); i++) {
        for (int j = 0; j < 3; j++) {
            line_long[i][j] = (long long)line[i][j];
        }
    }
    
    vector<vector<long long>> comb(2);
    combi(line_long, comb, 2, 0, 0, result);
    
    
    auto it1 = max_element(result.begin(), result.end(), [](vector<long long> a, vector<long long> b) {
        return a[0] < b[0];});
    auto it2 = max_element(result.begin(), result.end(), [](vector<long long> a, vector<long long> b) {
        return a[0] > b[0];});
    long long max_x = (*it1)[0];
    long long min_x = (*it2)[0];
    
    it1 = max_element(result.begin(), result.end(), [](vector<long long> a, vector<long long> b) {
        return a[1] < b[1];});
    it2 = max_element(result.begin(), result.end(), [](vector<long long> a, vector<long long> b) {
        return a[1] > b[1];});    
    long long max_y = (*it1)[1];
    long long min_y = (*it2)[1];
    
    long long height = max_y - min_y + 1;
    long long width = max_x - min_x + 1;
    vector<string> answer(height, string(width, '.'));
    
    long long offset_x = min_x;
    long long offset_y = max_y;
    
    for (auto &el : result) {
        answer[-(el[1] - offset_y)][el[0] - offset_x] = '*';
    }

    return answer;
}
