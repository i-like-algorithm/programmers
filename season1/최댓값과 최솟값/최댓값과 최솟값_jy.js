function solution(s) {
  let answer = "";
  let sArr = s.split(" ").map((e) => +e);
  answer = Math.min(...sArr) + " " + Math.max(...sArr);
  return answer;
}
