function solution(n) {
  let answer = 0,
    start = 1;

  while (start <= n / 2 + 1) {
    let sum = 0;
    for (let i = start; i >= 1; i--) {
      sum += i;
      if (sum === n) {
        answer++;
        break;
      }
      if (sum > n) break;
    }
    start++;
  }
  return ++answer;
}
