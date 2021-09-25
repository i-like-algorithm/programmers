function solution(n) {
  let answer = 0;

  for (let i = 1; i <= n; i++) {
    let inum = i;
    let tot = 0;
    while (1) {
      tot += inum;

      if (tot === n) {
        answer++;
        break;
      } else if (tot > n) {
        break;
      }
      inum++;
    }
    // console.log(tot);
    // [1,2,3,4,5] [2,3,4,5,6] [3,4,5,6] [4,5,6] [5,6,7] [6,7,8] [7,8] ...
  }
  return answer;
}
