function solution(n) {
  let binN = n.toString(2);
  let nOne = 0;
  for (let i = 0; i < binN.length; i++) {
    if (binN[i] === "1") nOne++;
  }
  let nextOne = 0;
  let next = n + 1;
  while (1) {
    let binNext = next.toString(2).split("");
    // for (let i = 0; i < binNext.length; i++) {
    //     if (binNext[i] === "1") nextOne++;
    // }
    // for문쓰면 시간초과남
    let filteredNext = binNext.filter((e) => e === "1");
    let nextOne = filteredNext.length;
    if (nextOne === nOne) return next;
    next++;
  }
}
