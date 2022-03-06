#include <string>
#include <vector>
#include <iostream>

using namespace std;

void set_triangle(vector<vector<int>> &triangle, int start_row, int start_col, int height, int *num) {
    int cur_row = start_row;
    int cur_col = start_col;
    int width = height;
    for (int i = 0; i < height; i++) {
        if (i == height - 1) {
            for (int j = 0; j < width; j++) {
                triangle[cur_row + i][cur_col + j] = (*num)++;
            }
        }
        else {
            triangle[cur_row + i][cur_col + 0] = (*num)++;
        }
    }
    for (int i = height - 2; i > 0; i--) {
        triangle[cur_row + i][cur_col + i] = (*num)++;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);
    int num = 1;
    int cur_row = 0;
    int cur_col = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            triangle[i].push_back(0);
        }
    }
    
    while (n > 0) {
        set_triangle(triangle, cur_row, cur_col, n, &num);
        n -= 3;
        cur_row += 2;
        cur_col++;
    }

    for (auto &el : triangle) {
        for (auto & el2 : el) {
            answer.push_back(el2);
        }
    }
    
    return answer;
}
