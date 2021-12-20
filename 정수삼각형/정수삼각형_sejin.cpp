#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int find_biggernum(const vector<vector<int>> &triangle, const int i, const int j) {
    int left_num;
    int right_num;

    if (j == 0) {
        return (triangle[i - 1][j]);
    }
    else if(j == triangle[i].size() - 1) {
        return (triangle[i - 1][j - 1]);
    }
    else {
        left_num = triangle[i - 1][j - 1];
        right_num = triangle[i - 1][j];
        return (max(left_num, right_num));
    }
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += find_biggernum(triangle, i, j);
        }
    }

    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}
