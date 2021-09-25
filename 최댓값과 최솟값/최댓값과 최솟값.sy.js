function solution(s) {
  let arr = s.split(" ").map((e) => parseInt(e));
  let ans = Math.min(...arr) + "" + " " + Math.max(...arr) + "";
  return ans;
}
