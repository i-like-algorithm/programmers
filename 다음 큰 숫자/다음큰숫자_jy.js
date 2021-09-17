function solution(n) {
  let nDec = n.toString(2);
  let nCnt = [...nDec].filter((e) => e === "1").length;
  while (1) {
    n++;
    if (nCnt === [...n.toString(2)].filter((e) => e === "1").length) return n;
  }
}
