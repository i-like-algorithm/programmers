function solution(A, B) {
  let answer = 0;
  let aSort = A.sort((a, b) => {
    return a - b;
  });
  let bSort = B.sort((a, b) => {
    return b - a;
  });
  for (let i = 0; i < aSort.length; i++) {
    answer += aSort[i] * bSort[i];
  }

  return answer;
}
