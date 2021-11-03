#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef struct pos {
    int x;
    int y;
}               pos;

int man_length(pos pos1, pos pos2) {
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

void dfs(vector<vector<pos>> &result, vector<pos> arr, vector<pos> comb, int r, int index, int depth) {
    if (r == 0) {
        result.push_back(comb);
    }
    else if (depth == arr.size())
        return ;
    else {
        comb[index] = arr[depth];
        dfs(result, arr, comb, r - 1, index + 1, depth + 1);
        dfs(result, arr, comb, r, index, depth + 1);
    }
}

bool chk_distance(vector<string> &arr) {
    vector<pos> persons;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'P')
                persons.push_back({i, j});
        }
    }
    
    vector<pos> comb(2);
    vector<vector<pos>> result;
    dfs(result, persons, comb, 2, 0, 0);
    
    for (auto &el : result) {
        for (auto &el2 : el) {
            cout << el2.x << ", " << el2.y << "     ";
        }
        cout << endl;
    }
    
    for (auto &row : result) {
        if (man_length(row[0], row[1]) > 2) {
            continue;
        }
        else if (man_length(row[0], row[1]) == 1) {
            return false;
        }
        else if (man_length(row[0], row[1]) == 2) {
            if (row[0].x == row[1].x) {
                if (row[0].y > row[1].y) {
                    if (arr[row[0].x][row[1].y + 1] != 'X')
                        return false;
                }
                else {
                    if (arr[row[0].x][row[0].y + 1] != 'X')
                        return false;
                }
            }
            else if (row[0].y == row[1].y) {
                if (row[0].x > row[1].x) {
                    if (arr[row[1].x + 1][row[0].y] != 'X')
                        return false;
                }
                else {
                    if (arr[row[0].x + 1][row[0].y] != 'X')
                        return false;
                }
            }
            else {
                if (arr[row[0].x][row[1].y] != 'X' || arr[row[1].x][row[0].y] != 'X') {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto &arr : places) {
        if (chk_distance(arr))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}
