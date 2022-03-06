function solution(brown, yellow) {
  let answer = [],
    sum = brown + yellow,
    flag = 1;
  // 가로 -2 * 세로 -2 = yellow
  for (let x = 3; ; x++) {
    for (let y = 3; y <= x; y++) {
      if ((x - 2) * (y - 2) == yellow && x * y == yellow + brown) {
        answer.push(x);
        answer.push(y);
        flag = 0;
        break;
      }
    }
    if (flag == 0) break;
  }
  return answer;
}
