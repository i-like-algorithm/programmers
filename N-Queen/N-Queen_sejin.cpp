#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool chkQueen(vector<vector<char>> &board, int x, int y, const int &n) {
    for (int i = 1; i < y + 1; i++) {
        if (board[y - i][x] == 'Q')
            return false;
    }
    for (int i = 1; i < y + 1 && i < x + 1; i++) {
        if (board[y - i][x - i] == 'Q')
            return false;
    }
    for (int i = 1; i < y + 1 && x + i < n; i++) {
        if (board[y - i][x + i] == 'Q')
            return false;
    }
    return true;
}

void dfs(int &answer, vector<vector<char>> &board, int x, int y, const int &n) {
    if (y == n - 1) {
        answer++;
        return ;
    }

    for (int i = 0; i < n; i++) {
        if (chkQueen(board, i, y + 1, n)) {
            board[y + 1][i] = 'Q';
            dfs(answer, board, i, y + 1, n);
            board[y + 1][i] = ' ';
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<char>> board(n, vector<char>(n, ' '));
    dfs(answer, board, -1, -1, n);

    return answer;
}
