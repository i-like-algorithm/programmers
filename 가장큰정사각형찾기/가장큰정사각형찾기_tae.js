function solution(board)
{   
    let row = board.length,
        col = board[0].length,
        boardCopy = board,
        answer = 0;
    
    if (row <= 1 || col <= 1)
        {
            for (let i = 0; i < row; i++)
                {
                    for (let j = 0; j < col; j++)
                        {
                            if (boardCopy[i][j] == 1) return 1;
                        }
                }
        }
    
    for (let i = 1; i < row; i++)
        {
            for (let j = 1; j < col; j++)
                {
                    if (boardCopy[i][j] != 0)
                        {
                            boardCopy[i][j] = Math.min(boardCopy[i-1][j], boardCopy[i][j-1], boardCopy[i-1][j-1]) + 1;
                            answer = Math.max(boardCopy[i][j], answer);
                        }
                }
        }
    
    return Math.pow(answer, 2);
}