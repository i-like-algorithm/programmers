#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_path(vector<vector<int>> &board, const int height, const int width) {
    int left_path, right_path;
    
    if (width - 1 > -1 && board[height][width - 1] != -1)
        left_path = board[height][width - 1];
    else
        left_path = 0;
    if (height - 1 > -1 && board[height - 1][width] != -1)
        right_path = board[height - 1][width];
    else
        right_path = 0;
    return left_path + right_path;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n, vector<int>(m, 0));
    board[0][0] = 1;
    for (auto &el : puddles) {
        board[el[1] - 1][el[0] - 1] = -1;
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != -1)
                board[i][j] += find_path(board, i, j) % 1000000007;
        }
    }
    
    return (board[n - 1][m - 1]);
}
