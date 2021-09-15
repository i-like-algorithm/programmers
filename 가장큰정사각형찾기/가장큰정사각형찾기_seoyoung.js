function solution(board) {
    let len = board.length; // 정사각형의 가능한 최대 길ㅇl
    for (let row = 1; row < board.length; row++) {
        for (let col = 1; col < board[row].length; col++) {
            if (board[row][col] === 1) {
                // (왼쪽, 위, 대각선 값 중 최소값) + 1 로 갱신
                board[row][col] = Math.min(board[row - 1][col], board[row][col - 1], board[row - 1][col - 1]) + 1;
            }
        }
    }
    // console.log(board);
    let maxArr = [];
    for (let row = 0; row < board.length; row++) {
            maxArr[row] =Math.max(...board[row]);
    }
    // console.log(maxArr);
    let side = Math.max(...maxArr);
    return (side * side);
}
