#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool chk_same_elm(vector<vector<int>> &arr, int length, int x, int y) {
    int val = arr[x][y];
    for (int i = x; i < x + length; i++) {
        for (int j = y; j < y + length; j++) {
            if (val != arr[i][j])
                return (false);
        }
    }
    for (int i = x; i < x + length; i++) {
        for (int j = y; j < y + length; j++) {
            arr[i][j] = -1;
        }
    }
    arr[x][y] = val;
    return (true);
}

void quadtree(vector<vector<int>> &arr, int length, int x, int y) {
    if (length == 1)
        return ;
    if (chk_same_elm(arr, length, x, y) == false) {
        quadtree(arr, length / 2, x, y);
        quadtree(arr, length / 2, x, y + length / 2);
        quadtree(arr, length / 2, x + length / 2, y);
        quadtree(arr, length / 2, x + length / 2, y + length / 2);
    }
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    quadtree(arr, arr.size(), 0, 0);

    for (auto &el : arr) {
        for (auto &el2 : el) {
            if (el2 == 0)
                answer[0]++;
            else if (el2 == 1)
                answer[1]++;
    }
    return answer;
}
